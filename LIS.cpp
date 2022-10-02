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

vector<int> LIS_Smaller(vector<int> array, int X) {

	vector<int> ret;
	int m;

	// Finish this shit lol
	if (array.size()==0) {
		print_sequence(ret);
		return ret;
	}

	vector<int> array2 = array;
	array2.pop_back();

	vector<int> m1 = LIS_Smaller(array2, X);
	int m_not = m1.size();

	if (*(array.end())<X) {
		vector<int> m2 = LIS_Smaller(array2, *(array.end()));
		int m_including = m2.size();
		m = max(m_not, 1 + m_including);

		if (m==m_not) {
			print_sequence(m1);
			return m1;
		}
		else {
			//m2.push_back(*(array.end()));
			print_sequence(m2);
			return m2;
		}

	}

	array.push_back(X);
	print_sequence(array);
	return array;

	// This entire function is just directly copied from notes.
	// Need to check correctness and logic.

}

vector<int> LIS(vector<int> array) {

	return LIS_Smaller(array, MAX_INFINITY);
	array.pop_back();

}

int main(void) {

	int n;
	cin >> n;

	vector<int> array = Take_Vector_Input(n);

	vector<int> Seq = LIS(array);

	// Prints LI Sequence
	print_sequence(Seq);

}