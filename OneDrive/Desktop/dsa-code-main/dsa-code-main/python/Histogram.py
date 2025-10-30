import cv2
import matplotlib.pyplot as plt

# Read the uploaded image in grayscale
img = cv2.imread('grayimg.jpeg', 0)

# Apply Histogram Equalization
equalized_img = cv2.equalizeHist(img)

# Show both images
cv2.imshow("Original Image", img)
cv2.imshow("Enhanced Image (Equalized)", equalized_img)


# Save histogram of original image as question1.png
plt.figure()
plt.hist(img.ravel(), bins=256, range=(0, 256))
plt.title("Histogram of Original Image")
plt.xlabel("Pixel Intensity")
plt.ylabel("Frequency")
plt.savefig("question1.png")
plt.close()  # Close the figure to free memory

# Save histogram of equalized image as question3.png
plt.figure()
plt.hist(equalized_img.ravel(), bins=256, range=(0, 256))
plt.title("Histogram of Equalized Image")
plt.xlabel("Pixel Intensity")
plt.ylabel("Frequency")
plt.savefig("question3.png")
plt.close()  # Close the figure

# Optionally, you can display the images using OpenCV if needed
cv2.imshow("Original Image", img)
cv2.imshow("Enhanced Image (Equalized)", equalized_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
