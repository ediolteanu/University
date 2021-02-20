#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

void input(int n, int id) {
	string outputFile = (string)"test" + to_string(id) + (string)".in";
	ofstream out(outputFile);
	random_device rd;

	vector< vector<int> > costs(n);
	for (int i = 0; i < n; i++) {
		costs.push_back(vector<int>(n));
	}

    int l;
    int o = 0;
    int rnd = 0;
	for (int i = 0; i < n; i++) {
	    l = 0;
		for (int j = 0; j < n; j++) {
            l++;
			if (i != j) {
                if (l % 10 == 0) {
                    //rnd = rd() % 100;
                    rnd = rd() % 10;
                    //rnd = (-1)*(rd() % 100);
                    if (rnd != 0) {
                        o++;
                    }
                    costs[i].push_back(rnd);
                } else {
                    //rnd = rd() % 100;
                    rnd = rd() % 10;
                    //rnd = (-1)*(rd() % 100);
                    if (rnd != 0) {
                        o++;
                    }
                    costs[i].push_back(rnd);
                }
			} else {
				costs[i].push_back(0);
			}
		}
	}
    int src;
    src = rand() % n + 1;
    k = 0;
	out << n << " " << o << " " << src <<endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            if (costs[i][j] != 0) {
                out<< i + 1 << " " << j + 1 << " " << costs[i][j] <<endl;
                out.flush();
			}
		}
		k++;
		out.flush();
	}
	out.close();
}

int main() {
	input(5, 10);
	input(10, 11);
	input(20, 12);
	input(30, 13);
	input(40, 14);
	input(50, 15);
	input(100, 16);
	input(200, 17);
	input(500, 18);
	input(1000, 19);
}
