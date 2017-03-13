def get_input():
    cars = []
    num_cars = input()
    for i in range (num_cars):
        cars.append(input())

    return cars

def calc(cars):
    aux = []
    aux.append(1)
    for j in range(1, len(cars)):
        len_seq = 0
        for k in range(j):
            if cars[j] > cars[k] and len_seq < aux[k]:
                len_seq = aux[k]
        aux.append(len_seq + 1)

    print max(aux)



if __name__ == '__main__':
    cars = get_input()
    calc(cars)
