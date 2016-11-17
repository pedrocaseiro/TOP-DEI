def get_input():
    cars = []
    num_cars = input()
    for i in range (num_cars):
        cars.append(input())

    return cars

def calc(cars):
    aux = []
    for i in range(len(cars)):
        aux.append(0)

    for j in range(len(cars)):
        len_seq = 0
        if j == 0:
            aux[0] = 1
        else:
            for k in range(1, j):
                if cars[j] > cars[k]:
                    if len_seq < aux[k]:
                        len_seq = aux[k]
            aux[j] = len_seq + 1            

    print max(aux)



if __name__ == '__main__':
    cars = get_input()
    calc(cars)
