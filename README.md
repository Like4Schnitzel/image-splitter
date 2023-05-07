# image-splitter
An image splitter written in C++ using OpenCV.

### Usage
Whether to scale the split parts to squares may be set to "false" with the second argument. Default is true.

Working directory may be specified as the first argument. Default is current working directory.\
First argument may also be a path to a single file.

If a single file is given the program will only attempt to split that. 
Otherwise the working directory will be walked through (non-recursively) and any existing image files (.png, .jpg, .jpeg or .webp) will be split.
The resulting images are written to a folder with the same name as the image, but with the filename cut off.
