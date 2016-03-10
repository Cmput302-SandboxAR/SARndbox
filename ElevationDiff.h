#include <Kinect/FrameBuffer.h>

// **
//  * @brief Subtracts values in frame buff b from frame buff a
//  * @return a frame buffer containing the difference
//  **
void BufferDifference(Kinect::FrameBuffer a, Kinect::FrameBuffer b)
{
    
    float* diPtrA=static_cast<float*>(a.getBuffer());
    float* diPtrB=static_cast<float*>(b.getBuffer());

    for(unsigned int y=0;y<a.getSize(1);++y)
        for(unsigned int x=0;x<a.getSize(0);++x,++diPtrA,++diPtrB)
            *diPtrA -= *diPtrB;
    
    
}