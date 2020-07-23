#define _CRT_SECURE_NO_WARNINGS

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

#include <conio.h>

#define PIXEL_THRESHOLD 12000

#define UP 'w'//72
#define LEFT 'a'//75
#define RIGHT 'd'//77
#define DOWN 's'//80
#define ESC 27

#define PAUSE 'p'
#define BRIGHT 'b'
#define CONTRAST 'c'
#define ADJUST 'a'
#define ROTATE 'r'
#define HIST 'h'
#define MOVE 'm'
#define SIZE 's'
#define FLIP 'f'
#define SNAPSHOT 't'

#define SHUTDOWN ESC

typedef enum FLIPCODE
{
	NORMAL_FLIP = -2,
	BILARTERAL_TOP_DOWN_FLIP = -1,
	TOP_DOWN_FLIP = 0,
	BILARTERAL_FLIP = 1
}FLIPCODE;

typedef struct size
{
	double col;
	double row;
}td_t;

class ImageProcess
{ //default constructor
public:
	int bright = 0;
	int contrast = 0;
	int rotate = 0;
	td_t move = { 0, 0 };
	td_t size = { 0, 0 };
	cv::Point2f inputQuad[4];
	int flip = NORMAL_FLIP;

	int adjust_enable = 0;
};

/********************************************/

int setQuadPoint(cv::Point2f inputQuad)
{
	td_t point = { 0, 0 };
	std::cout << "Call Set Quad mode" << std::endl;
	std::cout << "UP : ROW + 10" << std::endl;
	std::cout << "DOWN : ROW - 10" << std::endl;
	std::cout << "RIGHT : COL + 1" << std::endl;
	std::cout << "LEFT : COL - 1" << std::endl;

	while (1)
	{
		char ch = 0;
		char str[500];
		switch (ch = cv::waitKey(0))
		{
		case UP:
			point.row += 10;
			break;
		case DOWN:
			point.row -= 10;
			break;
		case RIGHT:
			point.col += 10;
			break;
		case LEFT:
			point.col -= 10;
			break;
		case ESC:
			inputQuad = cv::Point2f(point.row, point.col);
			std::cout << "Quad [x : ";
			std::cout << point.col << " y : " << point.row << std::endl;
			std::cout << "Exit Quad Setting Mode~" << std::endl;
			return 0;
			break;
		default:
			break;
		}
		std::cout << "Quad [x : ";
		std::cout << point.col << " y : " << point.row << "]" << std::endl;
	}
	return 0;
}


int setBright(cv::Mat inputImg, cv::Mat& outputImg)
{
	static int bright = 0;

	std::cout << "Call Set Bright mode" << std::endl;
	std::cout << "UP : bright + 10" << std::endl;
	std::cout << "DOWN : bright - 10" << std::endl;
	std::cout << "RIGHT : bright + 1" << std::endl;
	std::cout << "LEFT : bright - 1" << std::endl;

	while (1)
	{
		char ch = 0;
		switch (ch = cv::waitKey(0))
		{
		case UP:
			bright += 10;
			std::cout << "Bright : ";
			std::cout << bright << std::endl;
			break;
		case DOWN:
			bright -= 10;
			std::cout << "Bright : ";
			std::cout << bright << std::endl;
			break;
		case RIGHT:
			bright += 1;
			std::cout << "Bright : ";
			std::cout << bright << std::endl;
			break;
		case LEFT:
			bright -= 1;
			std::cout << "Bright : ";
			std::cout << bright << std::endl;
			break;
		case ESC:
			std::cout << "Bright : ";
			std::cout << bright << std::endl;
			std::cout << "Exit Bright Mode~" << std::endl;
			return bright;
			break;
		default:
			break;
		}
		std::cout << "Bright : ";
		std::cout << bright << std::endl;
	}
	return bright;
}
int setContrast(cv::Mat inputImg, cv::Mat& outputImg)
{
	static int contrast = 0;

	std::cout << "Call Set Contrast mode" << std::endl;
	std::cout << "UP : contrast + 10" << std::endl;
	std::cout << "DOWN : contrast - 10" << std::endl;
	std::cout << "RIGHT : contrast + 1" << std::endl;
	std::cout << "LEFT : contrast - 1" << std::endl;

	//cv::putText(inputImg, "Contrast Mode", cv::Point(inputImg.cols/2, inputImg.rows/2), 1, 2.5, cv::Scalar::all(255));
	//cv::imshow("Player", inputImg);

	while (1)
	{
		char ch = 0;
		char str[500];
		switch (ch = cv::waitKey(0))
		{
		case UP:
			contrast += 10;
			break;
		case DOWN:
			contrast -= 10;
			break;
		case RIGHT:
			contrast += 1;
			break;
		case LEFT:
			contrast -= 1;
			break;
		case ESC:
			std::cout << "Contast : ";
			std::cout << contrast << std::endl;
			std::cout << "Exit Contrast Mode~" << std::endl;
			return contrast;
			break;
		default:
			break;
		}
		std::cout << "Contast : ";
		std::cout << contrast << std::endl;
		//sprintf(str, "Contrast : %d", contrast);
		//cv::rectangle(inputImg, cv::Rect(inputImg.cols/3, inputImg.rows/2, inputImg.cols / 3 + 100, inputImg.rows / 2 + 30), cv::Scalar(255, 255, 255), -1);
		//cv::putText(inputImg, str, cv::Point(inputImg.cols / 3, inputImg.rows / 2 + 50), 1, 5, cv::Scalar::all(0));
		//cv::imshow("Player", inputImg);
	}
	return contrast;
}
int setRotate(cv::Mat inputImg, cv::Mat& outputImg)
{
	static int rotate = 0;

	std::cout << "Call Set Rotate mode" << std::endl;
	std::cout << "UP : Rotate + 10" << std::endl;
	std::cout << "DOWN : Rotate - 10" << std::endl;
	std::cout << "RIGHT : Rotate + 1" << std::endl;
	std::cout << "LEFT : Rotate - 1" << std::endl;

	while (1)
	{
		char ch = 0;
		char str[500];
		switch (ch = cv::waitKey(0))
		{
		case UP:
			rotate += 10;
			break;
		case DOWN:
			rotate -= 10;
			break;
		case RIGHT:
			rotate += 1;
			break;
		case LEFT:
			rotate -= 1;
			break;
		case ESC:
			std::cout << "Rotate : ";
			std::cout << rotate << std::endl;
			std::cout << "Exit Rotate Mode~" << std::endl;
			return rotate;
			break;
		default:
			break;
		}
		std::cout << "Rotate : ";
		std::cout << rotate << std::endl;
	}
	return rotate;
}
int setMove(cv::Mat inputImg, cv::Mat& outputImg, td_t& move)
{
	std::cout << "Call Set MOVE mode" << std::endl;
	std::cout << "UP : ROW + 10" << std::endl;
	std::cout << "DOWN : ROW - 10" << std::endl;
	std::cout << "RIGHT : COL + 1" << std::endl;
	std::cout << "LEFT : COL - 1" << std::endl;

	while (1)
	{
		char ch = 0;
		char str[500];
		switch (ch = cv::waitKey(0))
		{
		case UP:
			move.row += 10;
			break;
		case DOWN:
			move.row -= 10;
			break;
		case RIGHT:
			move.col += 10;
			break;
		case LEFT:
			move.col -= 10;
			break;
		case ESC:
			std::cout << "MOVE [x : ";
			std::cout << move.col << " y : " << move.row << std::endl;
			std::cout << "Exit Move Mode~" << std::endl;
			return 0;
			break;
		default:
			break;
		}
		std::cout << "MOVE [x : ";
		std::cout << move.col << " y : " << move.row << "]"<<std::endl;
	}
	return 0;
}
int setSize(cv::Mat inputImg, cv::Mat& outputImg, td_t& size)
{
	std::cout << "Call Set Size mode" << std::endl;
	std::cout << "UP : ROW + 10" << std::endl;
	std::cout << "DOWN : ROW - 10" << std::endl;
	std::cout << "RIGHT : COL + 1" << std::endl;
	std::cout << "LEFT : COL - 1" << std::endl;

	while (1)
	{
		char ch = 0;
		char str[500];
		switch (ch = cv::waitKey(0))
		{
		case UP:
			size.row += 10;
			break;
		case DOWN:
			size.row -= 10;
			break;
		case RIGHT:
			size.col += 10;
			break;
		case LEFT:
			size.col -= 10;
			break;
		case ESC:
			std::cout << "Size [x : ";
			std::cout << size.col << " y : " << size.row << "]" << std::endl;
			std::cout << "Exit Size Mode~" << std::endl;
			return 0;
			break;
		default:
			break;
		}
		std::cout << "SIZE [x : ";
		std::cout << size.col << " y : " << size.row << "]" << std::endl;
	}
	return 0;
}
int setFlip(cv::Mat inputImg, cv::Mat& outputImg)
{
	static int flip = true;

	std::cout << "Call Set Flip mode" << std::endl;
	std::cout << "UP : top-down flip" << std::endl;
	std::cout << "DOWN : bilateral flip" << std::endl;
	std::cout << "LEFT or RIGHT : top-down and bilateral flip" << std::endl;

	while (1)
	{
		char ch = 0;
		switch (ch = cv::waitKey(0))
		{
		case UP:
			std::cout << "top-down symmetry" << std::endl;
			flip = TOP_DOWN_FLIP;
			break;
		case DOWN:
			std::cout << "bilateral symmetry" << std::endl;
			flip = BILARTERAL_FLIP;
			break;
		case LEFT:
			std::cout << "normal" << std::endl;
			flip = NORMAL_FLIP;
			break;
		case RIGHT:
			std::cout << "top-down and bilateral symmetry" << std::endl;
			flip = BILARTERAL_TOP_DOWN_FLIP;
			break;
		case ESC:
			std::cout << "Flip = " << flip << std::endl;
			std::cout << "Exit Flip Mode~" << std::endl;
			return flip;
		default:
			break;
		}
		std::cout << "Flip = " << flip << std::endl;
	}
}
int setQuad(cv::Mat& outputImg, cv::Point2f* inputQuad)
{
	
	std::cout << "Call Set Quad mode" << std::endl;
	std::cout << "Clockwise setting from top left" << std::endl;
	std::cout << "UP : Top left" << std::endl;
	std::cout << "DOWN : Top right" << std::endl;
	std::cout << "RIGHT : Bottom right" << std::endl;
	std::cout << "LEFT : Bottom left" << std::endl;

	while (1)
	{
		char ch = 0;
		switch (ch = cv::waitKey(0))
		{
		case UP:
			setQuadPoint(inputQuad[0]);
			break;
		case DOWN:
			setQuadPoint(inputQuad[1]);
			break;
		case RIGHT:
			setQuadPoint(inputQuad[2]);
			break;
		case LEFT:
			setQuadPoint(inputQuad[3]);
			break;
		case ESC:
			return 1;
		default:
			break;
		}
	}

	return 1;
}

int main() {

	cv::VideoCapture cap("test1.mp4");
	cv::Mat inputImg;

	ImageProcess out;
	int fps = cap.get(cv::CAP_PROP_FPS);

	int capBright = 0;
	int capContrast = 0;

	cv::namedWindow("Player");

	while (1)
	{
		if (cap.get(cv::CAP_PROP_POS_FRAMES) == cap.get(cv::CAP_PROP_FRAME_COUNT))
			cap.open("test1.mp4");

		cap.read(inputImg);

		if (inputImg.empty())
		{
			std::cout << "Image load Failed!" << std::endl;
			return -1;
		}

		cv::Mat outputImg = inputImg;

		//이미지 전처리 설정
		switch (cv::waitKey(1000 / fps))
		{
		case PAUSE:
			std::cout << "Pause" << std::endl;
			while (cv::waitKey(0) != 27);
			break;
		case BRIGHT:
			out.bright = setBright(inputImg, outputImg);
			break;
		case CONTRAST:
			out.contrast = setContrast(inputImg, outputImg);
			break;
		case ADJUST:
			out.adjust_enable = setQuad(inputImg, out.inputQuad);
			break;
		case ROTATE:
			out.rotate = setRotate(inputImg, outputImg);
			break;
		case MOVE:
			setMove(inputImg, outputImg, out.move);
			break;
		case SIZE:
			setSize(inputImg, outputImg, out.size);
			break;
		case FLIP:
			out.flip = setFlip(inputImg, outputImg);
			break;
		case SHUTDOWN:
			std::cout << "bye~" << std::endl;
			cv::destroyAllWindows();
			return 0;
		}

		//이미지 전처리 실행
		if (out.bright)
		{
			//cv::cvtColor(inputImg, outputImg, cv::COLOR_BGR2YCrCb);
			//cv::Mat ycrcb[3];
			//cv::split(outputImg, ycrcb);
			//ycrcb[0] += out.bright;
			//cv::merge(ycrcb, 3, outputImg);
			//cv::cvtColor(outputImg, outputImg, cv::COLOR_YCrCb2BGR);
			capBright = cap.get(cv::CAP_PROP_BRIGHTNESS);
			capBright += out.bright;
			cap.set(capBright, cv::CAP_PROP_BRIGHTNESS);

			std::cout << "b : " << cap.get(cv::CAP_PROP_BRIGHTNESS) << "c : " << cap.get(cv::CAP_PROP_CONTRAST) << std::endl;
		}
		if (out.contrast)
		{
			//cv::cvtColor(inputImg, outputImg, cv::COLOR_BGR2HSV);
			//cv::Mat hsv[3];
			//cv::split(outputImg, hsv);
			//hsv[2] += out.contrast;
			//cv::merge(hsv, 3, outputImg);
			//cv::cvtColor(outputImg, outputImg, cv::COLOR_HSV2BGR);
			capContrast = cap.get(cv::CAP_PROP_CONTRAST);
			capContrast += out.contrast;
			cap.set(capContrast, cv::CAP_PROP_CONTRAST);

			std::cout << "b : " << cap.get(cv::CAP_PROP_BRIGHTNESS) << "c : " << cap.get(cv::CAP_PROP_CONTRAST) << std::endl;
		}
		/*if (out.rotate.col != NULL || out.rotate.row != NULL)
		{
			cv::Point2f srcPts[3], dstPts[3];

			srcPts[0] = cv::Point2f(0, 0);
			srcPts[1] = cv::Point2f(out.rotate.col - 1, out.rotate.row);
			srcPts[2] = cv::Point2f(out.rotate.col - 1, out.rotate.row);

			dstPts[0] = cv::Point2f(50, 50);
			dstPts[1] = cv::Point2f(out.rotate.col - 100, 0);
			dstPts[2] = cv::Point2f(out.rotate.col - 50, out.rotate.row);

			cv::Mat M(cv::getAffineTransform(srcPts, dstPts));
			cv::warpAffine(inputImg, outputImg, M, cv::Size());
		}*/
		if (out.rotate)
		{
			cv::Point2f cp(inputImg.cols / 2.f, inputImg.rows / 2.f);
			cv::Mat M = cv::getRotationMatrix2D(cp, out.rotate, 1);

			cv::warpAffine(inputImg, outputImg, M, cv::Size());
		}
		if (out.move.col || out.move.row)
		{
			cv::Mat M = cv::Mat_<double>({ 2, 3 }, { 1, 0, out.move.col, 0, 1, out.move.row });
			cv::warpAffine(inputImg, outputImg, M, cv::Size());
		}
		if (out.size.col || out.size.row)
		{
			cv::resize(inputImg, outputImg, cv::Size(inputImg.cols + out.size.col, inputImg.rows + out.size.row), 0, 0, cv::INTER_NEAREST);
		}
		if (out.flip != NORMAL_FLIP)
		{
			cv::flip(inputImg, outputImg, out.flip);
		}
		if (out.adjust_enable)
		{
			cv::Point2f outputQuad[4];

			outputQuad[0] = cv::Point2f(0, 0);
			outputQuad[1] = cv::Point2f(inputImg.cols - 1, 0);
			outputQuad[2] = cv::Point2f(inputImg.cols - 1, inputImg.rows - 1);
			outputQuad[3] = cv::Point2f(0, inputImg.rows - 1);
			
			cv::Mat lambda = getPerspectiveTransform(out.inputQuad, outputQuad);
			cv::warpPerspective(inputImg, outputImg, lambda, cv::Size());
		}
		std::cout << "b : " << out.bright << "c : " << out.contrast << "r : " << out.rotate 
			<< "m [ x :  " << out.move.col << "  y : " << out.move.row <<" ]"<<std::endl;
		cv::imshow("Player", outputImg);
	}

}
