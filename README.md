# Softw## Prerequisites

We assume you have at least some prior programming experience (loops, functions, branching). You don't need to know C++ deeply before starting, but you'll pick up the important parts as you go. We'll use C++ in later projects since it's the main language for robotics software.

### Version Control Setup

I highly recommend using GitHub Desktop
- Download and install [GitHub Desktop](https://desktop.github.com/)
- Sign in with your GitHub account
- Clone this repository: `https://github.com/uarm-artemis-official/Software-Onboarding`
- GitHub Desktop provides a visual interface for:
  - Viewing file changes and diffs
  - Making commits with descriptive messages
  - Pushing/pulling changes to/from GitHub
  - Managing branches and pull requests

**Why GitHub Desktop?**
- **Visual interface** - See your changes clearly with color-coded diffs
- **Beginner-friendly** - No need to memorize git commands
- **Integrated workflows** - Easy branch management and pull requests
- **Conflict resolution** - Visual merge conflict resolution tools Onboarding

Welcome to the software onboarding projects repository. This repository contains a series of onboarding projects designed to introduce new members to the fundamentals of autonomous aiming and autonomous navigation.

These projects are meant to provide hands-on experience with the technologies we use most frequently in software development. The onboarding starts simple and progressively builds up, covering concepts from deep learning-based object detection, to traditional computer vision techniques, and eventually into navigation and ROS2.


## Prerequisites

We assume you have at least some prior programming experience (loops, functions, branching). You don’t need to know C++ deeply before starting, but you’ll pick up the important parts as you go. We’ll use C++ in later projects since it’s the main language for robotics software.

### C++ Basics

Before diving in, make sure you’re comfortable with:

- Primitives: (int, float, bool, char)
- Basic constructs: (if/else, loops, functions)
- Data structures: (arrays, strings, vectors)
- Pointers & references: (what they are, why they matter)
- Classes & objects: (constructors, destructors, basic OOP)

### Computer Vision Concepts

Since a big part of our software stack involves **traditional** vision-based aiming, you’ll also need exposure to common techniques.

Traditional CV techniques:
- Thresholding (binary & adaptive): separating objects from background
- Contours: finding object boundaries
- Morphological operations: clean up noisy masks (erosion, dilation)
- Filtering: Gaussian blur, edge detection


## Projects
Each project is meant to be a small coding project that requires learning and understanding few concepts in order to complete it. If you are lost, take the opportunity to explore and problem solve on your own, this process is where the best learning happens. Of course, you can always reach out to a software co-lead or lead if you need guidance.


Below is a list of current onboarding projects with a small overview.

### Software Onboarding 1 - Intro to Object-Detection: 
- Learn the basics of deep learning-based object detection using YOLO.
- Explore how a detection pipeline works: model input → bounding boxes → visualization.
- You can download the dataset under the folder `Software-Onboarding-1` (the `_train`, `_val`, and `_test` folders)

### Software Onboarding 2 - Traditional CV C++: 
- Learn the fundamentals of C++ programming while implementing traditional CV techniques.
- Implement binary thresholding and contour detection using OpenCV in C++.
- Compare this approach with what you learned from YOLO in Onboarding Project 1.


### Software Onboarding 3 - Navigation & ROS2:
- Introduction to ROS2 (Robot Operating System) and its role in robotics software.
- Basic navigation stack concepts:
    - Nodes, topics, and services in ROS2
    - Sensor fusion basics (e.g., lidar, IMU, odometry)

