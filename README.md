# dpda-windows version

Distribution-preserving data-augmentation
1. Download a dataset: 
   - UC Merced Land Use Dataset: http://weegee.vision.ucmerced.edu/datasets/landuse.html
   - Intel Image Classification: https://www.kaggle.com/puneet6060/intel-image-classification
   - The Oxford-IIIT Pet Dataset: https://www.robots.ox.ac.uk/~vgg/data/pets/
3. Setup OpenCV version: 440
4. Setup Boost version: 1_74
5. Setup ImageMagick-7.0.10-Q16-HDRI
6. Change the paths in VS2019.bat and open the Visual Studio 2019 with provided VS2019.bat
7. You must create two folders named "images" and "results" in the project directory.
8. Create a folder under "images" named "train"
9. Create as many folders for your classes as you wish under the "train" folder (Sample data is provided).
10. Copy images to corresponding class folders -- png, jpg, and tiff are supported
11. Debug and run the project in Release X-64 mode
12. Augmentation settings can be adjusted by using the informative comments in the "dataAugmentationProject.cpp" file.




