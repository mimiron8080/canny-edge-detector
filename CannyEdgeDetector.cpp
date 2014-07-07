#include <highgui.h>
#include <cv.h>

IplImage* doCanny(
IplImage* in,
double lowThresh,
double highThresh,
double aperture
)
{
  IplImage* out=cvCreateImage(
  cvGetSize(in),
  IPL_DEPTH_8U,
  1
  );
  if(in->nChannels!=1)
    cvCvtColor(in,out,CV_BGR2GRAY);
  if(out!=NULL)
    cvCanny(out,out,lowThresh,highThresh,aperture);
  return out;
}

int main(int argc,char** argv)
{
  IplImage* in=cvLoadImage(argv[1],1);
  IplImage* out1=cvCreateImage(
  cvGetSize(in),
  in->depth,
  1
  );
  IplImage* out3=cvCreateImage(
  cvGetSize(in),
  in->depth,
  3
  );
  out1=doCanny(in,10,50,3);
  out3=doCanny(in,10,50,3);
  if(out1==NULL)
    return 0;
  if(out3==NULL)
    return 0;
  cvNamedWindow("in",CV_WINDOW_AUTOSIZE);
  cvNamedWindow("out1",CV_WINDOW_AUTOSIZE);
  cvNamedWindow("out3",CV_WINDOW_AUTOSIZE);
  cvShowImage("in",in);
  cvShowImage("out1",out1);
  cvShowImage("out3",out3);
  cvWaitKey(0);
  cvReleaseImage(&in);
  cvReleaseImage(&out1);
  cvReleaseImage(&out3);
  cvDestroyWindow("in");
  cvDestroyWindow("out1");
  cvDestroyWindow("out3");

  return 0;
}
