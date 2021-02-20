#include <iostream>
#include <fstream>
#include <cstdio>
#include <errno.h>
#include <vector>

#include "algo.h"

using namespace std;

#define NUM_TESTS 10
#define MAX_TEST_NAME_SIZE 32

int read_input(const char* input_file, vector< vector<int> > &input, int &N, int &M, int &src) {

	int ret;

	FILE* file = fopen(input_file, "r");
	if (file == NULL) {
		fprintf(stderr, "Invalid input file\n");
        return -1;
	}

	ret = fscanf(file, "%d %d %d", &N, &M, &src);

	if (ret != 3) {
		fclose(file);
		fprintf(stderr, "Invalid input file\n");
        return -1;
	}

	input.resize(M, vector<int>(3));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) {
			ret = fscanf(file, "%d", &input[i][j]);
			if (ret != 1) {
				fclose(file);
                fprintf(stderr, "Invalid input file\n");
                return -1;
			}
		}
	}

	fclose(file);
	return 0;
}

int verify_output(const char* reference_file,  vector<int> &expected, int N, int src) {

	FILE* file = fopen(reference_file, "r");
	if (file == NULL) {
		fprintf(stderr, "Invalid reference file\n");
        return -1;
	}

	int ret;
	for (int i = 0, elem; i < N; i++) {
        if (i == src) {
            elem = 0;
        } else {
            ret = fscanf(file, "%d", &elem);
            if (ret != 1) {
                fclose(file);
                fprintf(stderr, "Invalid reference file\n");
                return -1;
            }
        }
        expected[i] = elem;
	}
	fclose(file);
	return 0;
}

int run_test(const char* input_file, const char* reference_file) {
	int N, M, src;
	vector< vector<int> > edges;
	vector<int> expected, output;

	int ret;
	ret = read_input(input_file, edges, N, M, src);
	if (ret) {
		return -1;
	}

	output.resize(N);
	shortestPath(edges, N, src, M, output);

	expected.resize(N);
	ret = verify_output(reference_file, expected, N, src - 1);
	if (ret) {
		return -1;
	}
	if (output == expected) {
		cout<<"Passed!"<<endl;
	} else {
		cout<<"Failed!\n"<<endl;
	}
	return 0;
}

int main() {

	char input_test[MAX_TEST_NAME_SIZE],
		 reference_file[MAX_TEST_NAME_SIZE];

	for (int i = 0; i < NUM_TESTS; i++) {
		sprintf(input_test, "./other_tests/in/test2%d.in", i);
		sprintf(reference_file, "./other_tests/out/test2%d.out", i);

		printf("Running other_test 2%d.......", i);

		if (run_test(input_test, reference_file)) {
			fprintf(stderr, "Failed to run other_test 2%d\n", i);
			return -1;
		}
	}
    cout<<endl;
	return 0;
}
