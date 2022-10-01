#include <bits/stdc++.h>
using namespace std;

#define MAX_INFINITY 9999999

vector<int> Take_Vector_Input(int size) {
	// Returns a vector with <size> number of elements

	vector<int> array;

	for (auto i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;

		array.push_back(temp);
	}

	return array;

}

vector<int> LIS_Smaller(vector<int> array, int X) {

	vector<int> ret;

	// Finish this shit lol
	if (array.size()==0) {
		return ret;
	}

	vector<int> array2 = array;
	array2.pop_back();

	vector<int> m_vector = LIS_Smaller(array2, X);
	int m = m_vector.size();

	if (*(array.end())<X) {
		int m_ = LIS_Smaller(array2, *(array.end())).size();
		m = max(m, 1 + m_);
	}

	array.push_back(X);
	return array;

	// This entire function is just directly copied from notes.
	// Need to check correctness and logic.

}

vector<int> LIS(vector<int> array) {

	return LIS_Smaller(array, MAX_INFINITY);

}

void print_sequence(vector<int> Sequence) {
	// Prints a vector's elements.

	cout << "Size Of LIS = " << Sequence.size() << endl;

	if (Sequence.size() != 0)
	{
		cout << *(Sequence.begin());

		for (auto iter = Sequence.begin() + 1; iter < Sequence.end(); iter++)
		{
			cout << " " << *iter;
		}
	}
	cout << endl;

}

int main(void) {

	int n;
	cin >> n;

	vector<int> array = Take_Vector_Input(n);

	vector<int> Seq = LIS(array);

	// Prints LI Sequence
	print_sequence(Seq);

}