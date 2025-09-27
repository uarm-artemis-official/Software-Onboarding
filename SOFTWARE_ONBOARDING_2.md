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

## Prerequisites

**Required Software:**
- C++ compiler (GCC 7+ or Clang) with C++17 support
- CMake 3.16+
- OpenCV 4.0+

## Project Structure

```
Software-Onboarding-2/
├── CMakeLists.txt              # Build configuration
├── src/
│   └── main.cpp               # Single file with TODOs to complete
├── resources/                 # Place test robot images here
├── build/                     # Generated files (gitignored)
└── SOLUTIONS.txt              # For instructors only
```

**Design Philosophy:**
- **Single-file approach** - Everything in `main.cpp` for simplicity
- **Fill-in-the-blanks** - You complete TODO sections to learn
- **Easy color switching** - Comment/uncomment sections to test blue vs red
- **Real robot testing** - Use actual competition images

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
- [HSV Color Space](https://en.wikipedia.org/wiki/HSL_and_HSV)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [Quick C++ Video](https://www.youtube.com/watch?v=MNeX4EGtR5Y)
- [References & Pointers](https://www.youtube.com/watch?v=sxHng1iufQE)
