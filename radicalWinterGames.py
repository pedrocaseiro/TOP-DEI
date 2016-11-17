def read_input():
    tests = []
    n_tests = input()
    for i in range(n_tests):
        n_lines = input()
        test = []
        for j in range(n_lines):
            line = raw_input()
            l = map(int,line.split(" "))
            test.append(l)
        tests.append(test)
    return tests

def calc_scores(tests):
    j=1

    for i in range(len(tests)):
        tests[i][1][0]+=tests[i][0][0]
        tests[i][1][1]+=tests[i][0][0]
        for j in range(2,len(tests[i])):
            for k in range(len(tests[i][j])):
                if k==0:
                    tests[i][j][k]+=tests[i][j-1][k]
                elif k==(len(tests[i][j])-1):
                    tests[i][j][k]+=tests[i][j-1][k-1]
                else:
                    tests[i][j][k] = max(tests[i][j][k]+tests[i][j-1][k-1],tests[i][j][k]+tests[i][j-1][k])
        print max(tests[i][j])

if __name__ == '__main__':
    tests = read_input()
    calc_scores(tests)
