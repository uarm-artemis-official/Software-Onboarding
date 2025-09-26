

from ultralytics import YOLO
import torch

if torch.cuda.is_available():
    device = 0 
    print(f"Using GPU: {torch.cuda.get_device_name(0)}")
elif hasattr(torch.backends, 'mps') and torch.backends.mps.is_available():
    device = "mps" 
    print("Using Apple Silicon (MPS)")
else:
    device = "cpu"
    print("Using CPU")


model = YOLO("yolo11n.pt")    # load a pretrained model (recommended for training)

# Train with important parameters
results = model.train(
    data="data.yaml", # dataset config file
    epochs=50,
    imgsz=640, # input image size
    batch=16,                
    device=device, # Training device
    
    lr0=0.01, # initial learning rate
    patience=50, # early stopping patience
    
    val=True, # run validation during training
    plots=True, # generate training plots
    
    # data augmentation (optional)
    # hsv_h=0.015, # hue variation
    # hsv_s=0.7, # saturation variation
    # hsv_v=0.4, # brightness variation
    # fliplr=0.5, # horizonta flip probability
    # there are alot more parameters, feel free to check out the docs to learn more
)

print("Training completed!")
print("Results saved in: runs/detect/train/")

