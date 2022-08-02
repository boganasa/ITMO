#include <iostream>
#include <vector>
#ifndef ARCHIVE_H 
#define ARCHIVE_H 
class Archive
{
private:
	int NumberOfRequests;
	std::vector<std::vector <double> > directory;
public:
	void setNumberOfRequests(int);
	void setDirectory(int, double);
	void resizeDirectory(int size);
	void operator ++ ();
	int getSize();
	double SearchMiddle(int index);
	double SearchMedian(int index);
	void MergeSort(int index, int l, int r);


};
#endif