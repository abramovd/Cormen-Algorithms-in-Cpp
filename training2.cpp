#include <iostream>
#include <string>
#include<vector>
#include <unordered_map>
// 13.8 Smart Pointer

/*class SmartPointer {
private:
	T* ref;
	int* ref_count;
public:
	SmartPointer(T* ptr) {
		ref = ptr;
		ref_count = new int;
		*ref_count = 1;
	}
	
	SmartPointer(SmartPointer & ptr) {
		ref = ptr.ref;
		ref_count = ptr.ref_count;
		++(*ref_count);
	}
	
	SmartPointer<T>& operator = (SmartPointer & ptr) {
		if (*ref_count > 0) remove();
		if (this != &ptr) {
			ref = ptr.ref;
			ref_count = ptr.ref_count;
			++(*ref_count);
		}	
	}
	
	~SmartPointer() {
		remove();
	}
	
	void remove() {
		--(*ref_count);
		if (*ref_count == 0) {
			delete ref_count;
			delete ref;
			ref = NULL;
			ref_count = NULL;
		}
	}
	
};

int main() {
	return 0;
}*/

int LCSubStr(std::string X, std::string Y, int m, int n)
{
    // Create a table to store lengths of longest common suffixes of
    // substrings.   Notethat LCSuff[i][j] contains length of longest
    // common suffix of X[0..i-1] and Y[0..j-1]. The first row and
    // first column entries have no logical meaning, they are used only
    // for simplicity of program
    std::vector<std::vector<int> > LCSuff(m+1);
    for (int i = 0; i < m + 1; ++i)
    	LCSuff[i].reserve(n + 1);
    int result = 0;  // To store length of the longest common substring
 
    /* Following steps build LCSuff[m+1][n+1] in bottom up fashion. */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = std::max(result, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}

int main() {
	std::string st = "obamaputionyou";
	std::string s1 = "mapu";
	std::string s2 = "xytionsdx";
	std::cout << LCSubStr(st, s2, st.size(), s2.size());
	return 0;
}


