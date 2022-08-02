#include "Archive.h"



void Archive::setNumberOfRequests(int number)
{
	NumberOfRequests = number;
}
void Archive::setDirectory(int index, double Value)
{
	directory.at(index).push_back(Value);
}

void Archive::resizeDirectory(int size)
{
	directory.resize(size);
}

void Archive::operator ++ ()
{
	NumberOfRequests++;
}

int Archive::getSize()
{
	return directory.size();
}


double Archive::SearchMiddle(int index)
{
	double summ = 0;
	for (int j = 0; j < NumberOfRequests; j++)
	{
		summ += directory[index][j];
	}

	return (summ / NumberOfRequests);
}

double Archive::SearchMedian(int index)
{
	
	for (int j = 0; j < NumberOfRequests; j++)
	{
        MergeSort(index, 0, NumberOfRequests - 1);
		if (NumberOfRequests % 2 == 1)
		{
            return directory[index][NumberOfRequests / 2];
		}
		else
		{
			return 0.5 * (directory[index][NumberOfRequests - 1] + directory[index][NumberOfRequests - 2]);
		}
	}
}

void Archive::MergeSort(int index, int l, int r)
{
    if (l == r)
    {
        return;
    }
    int middle = (l + r) / 2;
    MergeSort(index, l, middle);
    MergeSort(index, middle + 1, r);
    int i = l;
    int j = middle + 1;
    double* c = new double[r - l + 1];
    for (int step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= middle) && (directory[index][i] < directory[index][j])))
        {
            c[step] = directory[index][i];
            i++;
        }
        else
        {
            c[step] = directory[index][j];
            j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++)
    {
        directory[index][l + step] = c[step];
    }
    delete[] c;
}