# Software Onboarding Project #1
This project is focused on introducing deep learning concepts, computer vision, and object detection using YOLO (You Only Look Once) models and the Ultralytics framework. You'll learn how to train, validate, and deploy DL object detection models.

## Project Description
You will be creating a YOLO-based object detection system that can identify and classify objects in images. This project involves training a deep learning model using a labeled dataset, implementing data preprocessing and augmentation techniques, and evaluating model performance. The system will be capable of detecting objects with bounding box predictions and confidence scores.

# Important Note: Training Time & Google Colab
Training an object detection model can be **very time-consuming**, especially on older hardware or systems without dedicated GPUs. On a CPU-only system, training could take couple hours or a lot.



**If your local training is taking too long, consider using Google Colab:**
- **What is Google Colab?** A free cloud-based Jupyter notebook platform that provides access to computing resources like GPUs 
- **Easy Setup:** Upload your dataset and run the same Python files in a Jupyter notebook environment
- **How to Use:** Visit [colab.research.google.com](https://colab.research.google.com), create a new notebook, upload your project files, and run your training code

This is especially recommended if you don't have a dedicated GPU or if training on your local machine takes more than 1-2 hours.

## Resources
[How YOLO Object Detection Works](https://www.youtube.com/watch?v=svn9-xV7wjk&t=170s)

https://docs.ultralytics.com/

[Quick Google Colab Video](https://www.youtube.com/watch?v=TqqkZLHoY0o)

[Neural Network - 3Blue1Brown](https://www.youtube.com/watch?v=aircAruvnKk)

[Tutorial Video of the Entire Process](https://www.youtube.com/watch?v=r0RspiLG260)
## Project Setup
You'll work with three main files: `train.py` for training, `test.py` for testing and visualization, and `data.yaml` for dataset configuration.

### Environment Setup
Create a virtual environment and install the required packages using the provided `requirements.txt`:

```bash
# Create and activate virtual environment first:
python -m venv .venv

# Activate (Windows): .venv\Scripts\activate
# Activate (Mac/Linux): source .venv/bin/activate

# Install dependencies
pip install -r requirements.txt
```

### Dataset Structure
Your dataset should follow the YOLO format with the following structure:
```
dataset/
├── _train/
│   ├── images/
│   └── labels/
├── _val/
│   ├── images/
│   └── labels/
└── _test/
    ├── images/
    └── labels/
```

Each label file should contain bounding box annotations in YOLO format:
```
class_id center_x center_y width height
```

Where all coordinates are normalized between 0 and 1. But the dataset you would have downloaded should already have this setup. 

## Dataset Configuration with data.yaml
The `data.yaml` file is needed for YOLO training as it defines your dataset structure and classes. Your project includes a pre-configured `data.yaml` file that should be customized for your specific dataset:

```yaml
# Dataset configuration for YOLO training
# Dataset paths (relative to this file!!)
train: ./_train/images
val: ./_val/images
test: ./_test/images

# Number of classes 
nc: 1

# Class names 
names:
  0: 'object'
```

**Important Notes:**
- Paths are relative to the `data.yaml` file location
- The `nc` (number of classes) must match your actual dataset
- Class names in the `names` section correspond to class IDs in your label files
- Make sure your folder structure matches the paths specified

## YOLO Model Selection
This project uses YOLOv11. The `train.py` script is configured to use `yolo11n.pt` (nano model):

- `yolo11n.pt` - Nano (fastest, smallest, good for learning)
- `yolo11s.pt` - Small (balanced speed/accuracy)
- `yolo11m.pt` - Medium (higher accuracy)
- `yolo11l.pt` - Large (best accuracy, slower)
- `yolo11x.pt` - Extra Large (highest accuracy, slowest)

The nano model is perfect for this project as it trains the quickest and still provides good results 

## Understanding Concepts
Although the code is simple, there's a lot happening under the hood when training a deep learning object detection model. Here's a high-level overview of the key concepts:

### Deep Learning & Neural Networks
Deep learning uses artificial neural networks with multiple layers to learn patterns from data. For object detection, these networks learn to identify features like edges, shapes, and textures that help recognize and locate objects in images.

### YOLO (You Only Look Once)
YOLO is a real-time object detection algorithm that processes the entire image in a single forward pass through the network. Unlike other methods that examine different parts of an image separately, YOLO divides the image into a grid and predicts bounding boxes and class probabilities simultaneously, making it very fast.

### Object Detection Process
1. **Input**: Raw image fed into the neural network
2. **Feature Extraction**: Network identifies important visual features
3. **Prediction**: Model outputs bounding box coordinates and class probabilities
4. **Post-processing**: Non-maximum suppression removes duplicate detections
5. **Output**: Final detections with confidence scores and bounding boxes


### Training Parameters
Neural networks are trained using several key parameters that control the learning process, some of the more important ones are:
- **Epochs**: Number of times the model sees the entire training dataset
- **Batch Size**: How many images are processed together in one step
- **Learning Rate**: How fast the model updates its weights (too high = unstable, too low = slow)
- **Image Size**: Resolution of input images (larger = more detail but slower training)

### Validation Dataset
The validation dataset is a separate set of images used to test the model during training without letting it "cheat" by seeing the answers. It's crucial because:
- **Prevents Overfitting**: Stops the model from just memorizing training data
- **Performance Monitoring**: Shows how well the model generalizes to new, unseen images
- **Early Stopping**: Training stops automatically when validation performance stops improving

### Key Performance Metrics
- **Precision**: Of all the objects the model detected, how many were actually correct? (Quality of detections)
- **Recall**: Of all the actual objects in the image, how many did the model find? (Completeness of detections)  
- **Accuracy**: Overall correctness - combines both precision and recall into a single score
- **mAP**: Mean Average Precision - the standard metric for object detection that considers both precision and recall across different confidence thresholds
- **mAP@50**: Mean Average Precision at 50% IoU threshold - measures how well bounding boxes overlap with ground truth
- **mAP@50-95**: Mean Average Precision across multiple IoU thresholds (0.5 to 0.95) - a stricter metric that requires more precise bounding box predictions. This is considered the gold standard for object detection evaluation as it tests the model's ability to make very accurate localizations, not just correct detections.


## Running the Project

### Step 1: Setup
```bash
# Install dependencies
pip install -r requirements.txt

# Verify your dataset structure matches data.yaml paths
# Make sure you have _train/, _val/, and _test/ folders with images/ and labels/
```

### Step 2: Training
```bash
# Start training (will take 30minutes to possibly a few hours depending on hardware)
python train.py

# Monitor progress in terminal - you'll see:
# - Training progress per epoch
# - Validation metrics (mAP, precision, recall)
# - Best model saving notifications
```

### Step 3: Testing and Evaluation
```bash
# Test your trained model interactively
python test.py

# Navigate through test images:
# - Any key: next image
# - ESC: exit
# - View detection results in real-time
```

### Project File Structure
```
Software-Onboarding-1/
├── train.py              # Training script
├── test.py               # Testing and visualization script
├── data.yaml             # Dataset configuration
├── requirements.txt      # Dependencies
├── _train/               # Training data
│   ├── images/
│   └── labels/
├── _val/                 # Validation data
│   ├── images/
│   └── labels/
├── _test/                # Test data
│   ├── images/
│   └── labels/
└── runs/                 # Training outputs (created automatically)
    └── detect/
        └── train/
            ├── weights/
            │   ├── best.pt    # Best model weights
            │   └── last.pt    # Final epoch weights
            └── results.png    # Training curves
```

## Hints

### For Training:
- **Check Results**: Review `runs/` folder for metrics and stats while training

### For Testing:
- **Confidence Tuning**: Adjust `conf=` threshold based on your needs and feel free to play around

### Troubleshooting:
- **"No trained model found"**: Run `train.py` first to create the model
- **Poor performance**: Increase epochs or other parameters, or try data augmentation
- **Slow training**: Use GPU if available OR use Google Colab or some other online GPU resource OR reduce epochs or other parameters
- **Balance Data**: Try to have similar numbers of images in train/val splits (should already be done)
- **Verify Paths**: Ensure `data.yaml` paths match your actual folder structure
- **Check Labels**: Make sure label files correspond to image files (should already be done)
