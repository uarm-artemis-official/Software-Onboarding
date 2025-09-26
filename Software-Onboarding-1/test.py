from ultralytics import YOLO
import torch
import os
import cv2

if torch.cuda.is_available():
    device = 0
    print(f"Using GPU: {torch.cuda.get_device_name(0)}")
elif hasattr(torch.backends, 'mps') and torch.backends.mps.is_available():
    device = "mps"
    print("Using Apple Silicon (MPS)")
else:
    device = "cpu"
    print("Using CPU")

model_path = "runs/detect/train/weights/best.pt"  # path to your trained model
if os.path.exists(model_path):
    model = YOLO(model_path)
    print(f"Loading trained model: {model_path}")
else:
    print("There was no trained model found, make sure the path is correct")



test_folder = "_test/images"
if os.path.exists(test_folder):
    test_images = [f for f in os.listdir(test_folder) if f.lower().endswith(('.jpg', '.jpeg', '.png'))]
    print(f"Found {len(test_images)} test images")
    print("Press any key to go to next image, 'q' to quit, 'ESC' to exit")
    
    for i, img_name in enumerate(test_images):
        img_path = os.path.join(test_folder, img_name)
        print(f"\nTesting ({i+1}/{len(test_images)}): {img_name}")
        
        original_image = cv2.imread(img_path)
        display_image = original_image.copy()
        
        results = model(
            img_path,
            conf=0.25, # confidence threshold
            iou=0.45, # IoU threshold
            device=device,         
        )
        
        for result in results:
            boxes = result.boxes
            if boxes is not None:                
                for box in boxes:
                    x1, y1, x2, y2 = box.xyxy[0].cpu().numpy().astype(int)
                    conf = float(box.conf[0])
                    print(f"Detection: {conf:.2f} confidence")
                    
                    color = (0, 255, 0)
                    cv2.rectangle(display_image, (x1, y1), (x2, y2), color, 2)
                    
                    label = f"Object: {conf:.2f}"
                    (label_width, label_height), _ = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.6, 2)
                    cv2.rectangle(display_image, (x1, y1 - label_height - 10), (x1 + label_width, y1), color, -1)
                    cv2.putText(display_image, label, (x1, y1 - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
        
        # addiing info to image
        info_text = f"Image {i+1}/{len(test_images)}: {img_name}"
        cv2.putText(display_image, info_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
        cv2.putText(display_image, "Press any key for next, 'ESC' to quit", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)
        
        # displaying final image with bbox predictions and text
        cv2.imshow('YOLO Detection Results', display_image)
        
        key = cv2.waitKey(0) & 0xFF
        
        if key == 27:  # ESC key
            break
    
    cv2.destroyAllWindows()
else:
    print(f"Test folder '{test_folder}' not found!")

