#include <Kinect/FrameBuffer.h>
#include <cmath>

// **
//  * @brief Subtracts values in frame buff b from frame buff a
//  * @return a frame buffer containing the difference
//  **
void BufferDifference(Kinect::FrameBuffer a, Kinect::FrameBuffer b, Kinect::FrameBuffer out)
{
    float* diPtrA=static_cast<float*>(a.getBuffer());
    float* diPtrB=static_cast<float*>(b.getBuffer());
    float* diPtrOut=static_cast<float*>(out.getBuffer());

    for(unsigned int y=0;y<a.getSize(1);++y)
        for(unsigned int x=0;x<a.getSize(0);++x,++diPtrA,++diPtrB, ++diPtrOut)
            *diPtrOut = *diPtrA - *diPtrB;
}

void BufferAddition(Kinect::FrameBuffer a, Kinect::FrameBuffer b, Kinect::FrameBuffer out)
{
    float* diPtrA=static_cast<float*>(a.getBuffer());
    float* diPtrB=static_cast<float*>(b.getBuffer());
    float* diPtrOut=static_cast<float*>(out.getBuffer());

    for(unsigned int y=0;y<a.getSize(1);++y)
        for(unsigned int x=0;x<a.getSize(0);++x,++diPtrA,++diPtrB, ++diPtrOut)
            *diPtrOut = *diPtrA + *diPtrB;
}

float BufferError(Kinect::FrameBuffer a, Kinect::FrameBuffer b)
{
    float* diPtrA=static_cast<float*>(a.getBuffer());
    float* diPtrB=static_cast<float*>(b.getBuffer());
    float out = 0.0;

    for(unsigned int y=0;y<a.getSize(1);++y)
        for(unsigned int x=0;x<a.getSize(0);++x,++diPtrA,++diPtrB)
            out += std::abs(*diPtrA - *diPtrB);

    return out;
}