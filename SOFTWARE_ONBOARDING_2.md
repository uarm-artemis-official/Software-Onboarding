# Software Onboarding Project #2: Lightbar Detection

For the second software onboarding project, you'll build a **real-world computer vision system** based on C++ to detect LED lightbars on RoboMaster robots using C++ and OpenCV.

## What You'll Learn

- **HSV color space** - Why it's better than RGB for robotics
- **Binary thresholding** - Isolating specific colors from images  
- **Morphological operations** - Cleaning up noisy detections
- **Contour detection** - Finding object boundaries
- **Real-world CV challenges** - Lighting, noise, and parameter tuning

## Real-World Context
In RoboMaster competitions, robots have **LED lightbars** that serve as:
- **Targeting points** - Where you aim to score hits
- **Team identification** - Blue vs red teams
- **Visual feedback** - Robot status and health

Your detector needs to work reliably under various lighting conditions and angles.

## Prerequisites & Installation

### **Windows Installation**

Make sure on VSCode you install these extensions:
**C/C++ for Visual Studio Code**
**CMake**
**CMake Tools**

(You can watch this video as a guide)[https://www.youtube.com/watch?v=m9HBM1m_EMU]



Just install the most recent versions:

[CMake Download](https://cmake.org/download/)
- Make sure you are downloading Windows x64 Installer under Binary Distributions

[OpenCV Download](https://opencv.org/releases/)
- Download "Windows"


Make sure the CMake path, and the two OpenCV paths are part of the environment variables 


#### **macOS Installation**

**Install Xcode Command Line Tools (C++ compiler):**
```bash
# Install Xcode command line tools (includes clang++)
xcode-select --install

# Verify installation
clang++ --version
# Should show: Apple clang version 12.0+ with C++17 support
```

**Install Package Manager (Homebrew):**
```bash
# Install Homebrew if you don't have it
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

[OpenCV C++ & CMake Installation Docs](https://docs.opencv.org/3.4/d0/db2/tutorial_macos_install.html)

**Install CMake and OpenCV:**
```bash
# Install CMake
brew install cmake

# Install OpenCV
brew install opencv

# Verify installations
cmake --version    # Should show 3.16+
pkg-config --modversion opencv4    # Should show OpenCV version
```

#### **Linux (Ubuntu/Debian) Installation**

**Install C++ Compiler:**
```bash
# Update package list
sudo apt update

# Install GCC compiler and build essentials
sudo apt install build-essential g++

# Verify installation
g++ --version
# Should show: g++ (GCC) 7.0+ with C++17 support
```

**Install CMake:**
```bash
# Install CMake
sudo apt install cmake

# Verify installation
cmake --version    # Should show 3.16+
```

**Install OpenCV:**
```bash
# Install OpenCV development packages
sudo apt install libopencv-dev

# For newer versions, you might need:
sudo apt install libopencv-contrib-dev

# Verify installation
pkg-config --modversion opencv4
```

- Open the project folder in VS Code: `code Software-Onboarding-2/`
- Use `Ctrl+Shift+P` → "CMake: Configure" to set up the project
- Use `Ctrl+Shift+P` → "CMake: Build" to compile your code
- IntelliSense will help with OpenCV function completion

## Project Structure

```
Software-Onboarding-2/
├── CMakeLists.txt              # Build configuration
├── src/
│   ├── main.cpp               # Single file with TODOs to complete
│   └── test_setup.cpp         # Simple test to verify C++ installation
├── resources/                 # Place test robot images here
├── build/                     # Generated files (gitignored)
└── SOLUTIONS.txt              # For instructors only
```

**Design Philosophy:**
- **Single-file approach** - Everything in `main.cpp` for simplicity
- **Fill-in-the-blanks** - You complete TODO sections to learn
- **Easy color switching** - Comment/uncomment sections to test blue vs red
- **Real robot testing** - Use actual competition images

## Quick Setup Test

**Before starting the main project, test your C++ installation:**

### **macOS Users:**
```bash
# Navigate to the source directory
cd Software-Onboarding-2/src

# Compile the test file (using clang++ from Xcode tools)
clang++ -std=c++17 test_setup.cpp -o test_setup
# OR using g++ if you installed it via Homebrew
g++ -std=c++17 test_setup.cpp -o test_setup

# Run the test
./test_setup
# Expected output: "Hello World!"
```

### **Linux Users:**
```bash
# Navigate to the source directory  
cd Software-Onboarding-2/src

# Compile the test file
g++ -std=c++17 test_setup.cpp -o test_setup

# Run the test
./test_setup
# Expected output: "Hello World!"
```

### **Windows Users:**

**Using MinGW/MSYS2:**
```bash
# Navigate to the source directory
cd Software-Onboarding-2/src

# Compile the test file
g++ -std=c++17 test_setup.cpp -o test_setup.exe

# Run the test
./test_setup.exe
# Expected output: "Hello World!"
```

**Using Visual Studio:**
```cmd
# From Developer Command Prompt, navigate to source directory
cd Software-Onboarding-2\src

# Compile the test file
cl /std:c++17 test_setup.cpp

# Run the test
test_setup.exe
# Expected output: "Hello World!"
```

## Computer Vision Pipeline

Your `main.cpp` implements a 5-step detection pipeline:

**Step 1: Color Space Conversion**
- Convert BGR → HSV for robust color detection
- HSV separates color from lighting conditions

**Step 2: Color Thresholding** 
- Define HSV ranges for blue or red lightbars
- Create binary mask (white = target color, black = everything else)

**Step 3: Morphological Cleaning**
- Remove noise with "opening" operation
- Fill gaps with "closing" operation

**Step 4: Contour Detection**
- Find connected white regions in cleaned mask
- Each contour = potential lightbar

**Step 5: Filtering & Visualization**
- Filter by area to remove false positives
- Draw bounding boxes around valid detections

## Key Concepts

**Why HSV over RGB?**
- **Hue** stays consistent under different lighting
- **Saturation** and **Value** can vary without affecting color identity
- Much more robust for real-world robotics

**Blue vs Red Detection:**
- **Blue** (100-130 hue) - Easier, good starting point
- **Red** (0-10 hue) - Trickier due to HSV wrap-around

**Morphological Operations:**
- **Opening** = Erosion + Dilation (removes noise)
- **Closing** = Dilation + Erosion (fills gaps)
- Essential for cleaning real-world image noise

## Getting Started

**1. Build the project:**
```bash
cd Software-Onboarding-2
mkdir build && cd build
cmake ..
make
# Creates: ./bin/lightbar_detector
```

**2. Complete the TODOs in `main.cpp`:**
- Image loading with `imread()`
- HSV conversion with `cvtColor()`
- Color range definition (HSV bounds)
- Binary masking with `inRange()`
- Morphological operations with `morphologyEx()`
- Contour detection with `findContours()`
- Bounding box drawing with `rectangle()`

**3. Choose your target color:**
- Look at the image you are testing on to see if you need to use the blue or red detection
- **Blue detection** - Uncommented by default, easier to start with
- **Red detection** - Comment out blue section, uncomment red section

**4. Test with robot images:**s
```bash
# Default test image
./bin/lightbar_detector

# Your own image
./bin/lightbar_detector ../resources/[image]
```

## What You'll See

**Visual Output:** 5 windows showing the detection pipeline
1. **Original Image** - Input robot image
2. **HSV Image** - Color space conversion
3. **Color Threshold** - Binary mask (white = detected color)
4. **Cleaned Mask** - After noise removal
5. **Final Result** - Bounding boxes on original image

**Console Output:** Detection statistics and area calculations


## Real-World Impact

This lightbar detection is used for:
- **Autonomous targeting** in RoboMaster competitions
- **Team identification** systems
- **Industrial quality control**
- **Medical imaging** applications
- **Autonomous vehicle** sign recognition

## Learning Resources

- [OpenCV Documentation](https://docs.opencv.org/4.x/index.html)
- [HSV Color Space](https://opencv.org/blog/color-spaces-in-opencv/)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [Quick C++ Video](https://www.youtube.com/watch?v=MNeX4EGtR5Y)
- [References & Pointers](https://www.youtube.com/watch?v=sxHng1iufQE)
