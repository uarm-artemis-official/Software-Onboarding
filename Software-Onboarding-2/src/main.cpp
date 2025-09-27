#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    // Check if image path is provided
    string imagePath;
    if (argc > 1) {
        imagePath = argv[1];
    } else {
        imagePath = "../resources/[image].jpg"; // put image name here to test the algorithm
    }

    // TODO: Load the image using cv::imread()
    // Hint: Mat image = imread(path);
    Mat image = /* TODO: Load image */;
    
    // Check if image was loaded successfully
    if (image.empty()) {
        cerr << "Error: Could not load image from " << imagePath << endl;
        cerr << "Usage: ./lightbar_detector [image_path]" << endl;
        return -1;
    }

    cout << "=== Simple Lightbar Detection ===" << endl;
    cout << "Image loaded: " << imagePath << endl;
    cout << "Image size: " << image.cols << "x" << image.rows << endl;

    // Step 1: Convert to HSV color space for better color detection
    cout << "\nStep 1: Converting to HSV color space..." << endl;
    Mat hsvImage;
    // TODO: Convert BGR image to HSV
    // Hint: cvtColor(input, output, COLOR_BGR2HSV);
    /* TODO: Convert image to HSV */

    // ==========================================================
    // CHOOSE YOUR COLOR: Comment/uncomment the section you want to test
    // ==========================================================
    
    // OPTION 1: BLUE LIGHTBAR DETECTION
    // Uncomment this section to detect blue lightbars
    cout << "Step 2: Creating color threshold for BLUE lightbars..." << endl;
    
    // TODO: Define HSV range for blue LEDs
    // Blue LEDs typically have:
    // - Hue: 100-130 (blue range in HSV)
    // - Saturation: 50-255 (allow some variation)
    // - Value: 50-255 (bright LEDs)
    Scalar lowerBound = /* TODO: Define lower HSV bound for blue */;
    Scalar upperBound = /* TODO: Define upper HSV bound for blue */;
    string colorName = "Blue";
    Scalar boundingBoxColor = Scalar(255, 0, 0);  // Blue color for bounding box
    
    /*
    // OPTION 2: RED LIGHTBAR DETECTION  
    // Uncomment this section to detect red lightbars (and comment out blue section above)
    cout << "Step 2: Creating color threshold for RED lightbars..." << endl;
    
    // TODO: Define HSV range for red LEDs
    // Red LEDs are tricky because red wraps around in HSV:
    // - Hue: 0-10 OR 170-180 (red spans around the hue circle)
    // - Saturation: 50-255 (allow some variation)
    // - Value: 50-255 (bright LEDs)
    // Note: For simplicity, we'll use 0-10 range (most common red)
    Scalar lowerBound = Scalar(0, 50, 50);     // TODO: Fill in correct values
    Scalar upperBound = Scalar(10, 255, 255);  // TODO: Fill in correct values
    string colorName = "Red";
    Scalar boundingBoxColor = Scalar(0, 0, 255);  // Red color for bounding box
    */
    
    // TODO: Create binary mask using cv::inRange()
    // This will create a white mask where the chosen color pixels are detected
    Mat colorMask;
    /* TODO: Create color mask using inRange() */

    // Step 3: Clean up the mask using morphological operations
    cout << "Step 3: Cleaning up the mask..." << endl;
    
    // TODO: Create a kernel for morphological operations
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
    
    // TODO: Apply opening (removes noise) then closing (fills gaps)
    Mat cleanMask;
    /* TODO: Apply morphologyEx with MORPH_OPEN on colorMask */
    /* TODO: Apply morphologyEx with MORPH_CLOSE on the result */

    // Step 4: Find contours in the clean mask
    cout << "Step 4: Finding lightbar contours..." << endl;
    
    // TODO: Find contours in the cleaned mask
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    /* TODO: Use findContours() to detect contours */
    
    cout << "Found " << contours.size() << " contours" << endl;

    // Step 5: Filter contours by area and draw bounding boxes
    cout << "Step 5: Drawing bounding boxes around lightbars..." << endl;
    
    Mat resultImage = image.clone();
    int lightbarCount = 0;
    
    for (size_t i = 0; i < contours.size(); i++) {
        // TODO: Calculate contour area
        double area = /* TODO: Calculate area using contourArea() */;
        
        // Only keep contours with reasonable area (filter noise)
        if (area > 100) {  // Minimum area threshold
            lightbarCount++;
            
            // TODO: Calculate bounding rectangle
            Rect boundingBox = /* TODO: Use boundingRect() */;
            
            // TODO: Draw rectangle around the lightbar
            // Use the boundingBoxColor defined above (blue or red depending on your choice)
            /* TODO: Draw rectangle using rectangle() function */
            
            // Add label
            string label = colorName + " Lightbar " + to_string(lightbarCount);
            Point labelPos(boundingBox.x, boundingBox.y - 10);
            putText(resultImage, label, labelPos, FONT_HERSHEY_SIMPLEX, 0.6, boundingBoxColor, 2);
            
            cout << "  Lightbar " << lightbarCount << ": Area = " << (int)area 
                 << ", Position = (" << boundingBox.x << ", " << boundingBox.y << ")" << endl;
        }
    }

    // Summary
    cout << "\n=== Detection Summary ===" << endl;
    cout << "Total lightbars detected: " << lightbarCount << endl;

    // Display results
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);
    waitKey(1);
    
    namedWindow("HSV Image", WINDOW_AUTOSIZE);
    imshow("HSV Image", hsvImage);
    waitKey(1);
    
    namedWindow(colorName + " Color Threshold", WINDOW_AUTOSIZE);
    imshow(colorName + " Color Threshold", colorMask);
    waitKey(1);
    
    namedWindow("Cleaned Mask", WINDOW_AUTOSIZE);
    imshow("Cleaned Mask", cleanMask);
    waitKey(1);
    
    namedWindow("Lightbar Detection Result", WINDOW_AUTOSIZE);
    imshow("Lightbar Detection Result", resultImage);

    cout << "\nPress any key on the image windows to exit..." << endl;
    waitKey(0);
    destroyAllWindows();

    return 0;
}
