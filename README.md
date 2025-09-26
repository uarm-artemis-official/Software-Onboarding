Welcome to the software onboarding projects repository. This repository contains a series of increasingly complex onboarding projects designed to introduce new members to the fundamentals of autonomous aiming and autonomous navigation.

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

Demo projects are included in the repository for demostrating the intended end behavior. These are minimal prototypes just meant to showcase the end result. The demos should looked at after you have completed the project or when you are completely stuck after looking at the instructions, hints, and asking for help from an onboarding instructor.

Each project will be accompanied by a write-up which describe the desired end result and provide some information which may be helpful for completing it. However, these write-ups are not comprehensive and will not contain everything necessary for completing the project, thus you'll have to do some digging around on the internet.

Below is a list of current onboarding projects with a small overview and their status.

### Software Onboarding 1 - Intro to Object-Detection: 
- Learn the basics of deep learning-based object detection using YOLO.
- Explore how a detection pipeline works: model input → bounding boxes → visualization.
- [Dataset](https://github.com/HaoqinHong/GKD-RoboMaster-Five-Point-Dataset/tree/master): This a link to the dataset that will be needed train the YOLO model
Main Takeaways:

Understand how modern object detection works.

Hands-on with YOLO (Python).

First exposure to connecting vision to robotics applications.
### Software Onboarding 2 - Traditional CV C++: 
- Learn the fundamentals of C++ programming while implementing traditional CV techniques.
- Implement binary thresholding and contour detection using OpenCV in C++.
- Compare this approach with what you learned from YOLO in Onboarding Project 1.


Main Takeaways:

Practical C++ coding experience.

Introduction to image processing pipelines.

Deeper understanding of how computer vision worked before deep learning.

### Software Onboarding 3 - Navigation & ROS2:
- Introduction to ROS2 (Robot Operating System) and its role in robotics software.
- Basic navigation stack concepts:
    - Nodes, topics, and services in ROS2
    - Sensor fusion basics (e.g., lidar, IMU, odometry)

Main Takeaways:
Set up and run a ROS2 workspace.
Understand the building blocks of robot navigation software.
Exposure to how our navigation systems tie into aiming and contro