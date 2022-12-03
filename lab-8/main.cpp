#include <iostream>
#include <vector>

using namespace std;


template<typename Type>
Type BubbleSort(Type arr[], unsigned int size) {
    bool flag = false;
    Type counter = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 1; j < size - i; j++) {
            if (++counter && arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
    return counter;
}


template<typename Type>
Type selectionSort(vector<Type> &arr, unsigned int size) {
    int min;
    Type counter = 0;
    bool isSwapped = false;
    int min_index;
    for (int j = 1; j < size; j++) {
        min = arr[j - 1];
        min_index = j - 1;
        int i = j;
        while (arr[i] > min || i < size) {
            counter++;
            if (arr[i] < min) {
                counter++;
                min = arr[i];
                min_index = i;
            }
            i++;
        }
        if (min_index != j - 1) {
            counter++;
            swap(arr[j - 1], arr[min_index]);
            isSwapped = true;
        }
    }


    return counter;
}

template<typename Type>
Type InsSort(Type arr[], unsigned int size) {
    Type temp;
    int counter = 0;
    int k = 1;
    if (++counter && arr[1] < arr[0]) {
        swap(arr[1], arr[0]);
        k = 2;
    }
    for (int i = k; i < size; i++) {
        if (++counter && arr[i] < arr[i - 1]) {
            temp = arr[i];
            arr[i] = arr[i - 1];
            int j = i - 2;
            while (++counter && arr[j] > temp) {
                arr[j + 1] = arr[j];
                if (j != 0) j--;
                else break;
            }
            arr[j] = temp;
        }
    }
    return counter;
}

int main() {

    /*float Array_Permutations[120][5] = {
            {5, 4, 3, 2, 1},
            {5, 4, 3, 1, 2},
            {5, 4, 2, 3, 1},
            {5, 4, 2, 1, 3},
            {5, 4, 1, 3, 2},
            {5, 4, 1, 2, 3},
            {5, 3, 4, 2, 1},
            {5, 3, 4, 1, 2},
            {5, 3, 2, 4, 1},
            {5, 3, 2, 1, 4},
            {5, 3, 1, 4, 2},
            {5, 3, 1, 2, 4},
            {5, 2, 4, 3, 1},
            {5, 2, 4, 1, 3},
            {5, 2, 3, 4, 1},
            {5, 2, 3, 1, 4},
            {5, 2, 1, 4, 3},
            {5, 2, 1, 3, 4},
            {5, 1, 4, 3, 2},
            {5, 1, 4, 2, 3},
            {5, 1, 3, 4, 2},
            {5, 1, 3, 2, 4},
            {5, 1, 2, 4, 3},
            {5, 1, 2, 3, 4},
            {4, 5, 3, 2, 1},
            {4, 5, 3, 1, 2},
            {4, 5, 2, 3, 1},
            {4, 5, 2, 1, 3},
            {4, 5, 1, 3, 2},
            {4, 5, 1, 2, 3},
            {4, 3, 5, 2, 1},
            {4, 3, 5, 1, 2},
            {4, 3, 2, 5, 1},
            {4, 3, 2, 1, 5},
            {4, 3, 1, 5, 2},
            {4, 3, 1, 2, 5},
            {4, 2, 5, 3, 1},
            {4, 2, 5, 1, 3},
            {4, 2, 3, 5, 1},
            {4, 2, 3, 1, 5},
            {4, 2, 1, 5, 3},
            {4, 2, 1, 3, 5},
            {4, 1, 5, 3, 2},
            {4, 1, 5, 2, 3},
            {4, 1, 3, 5, 2},
            {4, 1, 3, 2, 5},
            {4, 1, 2, 5, 3},
            {4, 1, 2, 3, 5},
            {3, 5, 4, 2, 1},
            {3, 5, 4, 1, 2},
            {3, 5, 2, 4, 1},
            {3, 5, 2, 1, 4},
            {3, 5, 1, 4, 2},
            {3, 5, 1, 2, 4},
            {3, 4, 5, 2, 1},
            {3, 4, 5, 1, 2},
            {3, 4, 2, 5, 1},
            {3, 4, 2, 1, 5},
            {3, 4, 1, 5, 2},
            {3, 4, 1, 2, 5},
            {3, 2, 5, 4, 1},
            {3, 2, 5, 1, 4},
            {3, 2, 4, 5, 1},
            {3, 2, 4, 1, 5},
            {3, 2, 1, 5, 4},
            {3, 2, 1, 4, 5},
            {3, 1, 5, 4, 2},
            {3, 1, 5, 2, 4},
            {3, 1, 4, 5, 2},
            {3, 1, 4, 2, 5},
            {3, 1, 2, 5, 4},
            {3, 1, 2, 4, 5},
            {2, 5, 4, 3, 1},
            {2, 5, 4, 1, 3},
            {2, 5, 3, 4, 1},
            {2, 5, 3, 1, 4},
            {2, 5, 1, 4, 3},
            {2, 5, 1, 3, 4},
            {2, 4, 5, 3, 1},
            {2, 4, 5, 1, 3},
            {2, 4, 3, 5, 1},
            {2, 4, 3, 1, 5},
            {2, 4, 1, 5, 3},
            {2, 4, 1, 3, 5},
            {2, 3, 5, 4, 1},
            {2, 3, 5, 1, 4},
            {2, 3, 4, 5, 1},
            {2, 3, 4, 1, 5},
            {2, 3, 1, 5, 4},
            {2, 3, 1, 4, 5},
            {2, 1, 5, 4, 3},
            {2, 1, 5, 3, 4},
            {2, 1, 4, 5, 3},
            {2, 1, 4, 3, 5},
            {2, 1, 3, 5, 4},
            {2, 1, 3, 4, 5},
            {1, 5, 4, 3, 2},
            {1, 5, 4, 2, 3},
            {1, 5, 3, 4, 2},
            {1, 5, 3, 2, 4},
            {1, 5, 2, 4, 3},
            {1, 5, 2, 3, 4},
            {1, 4, 5, 3, 2},
            {1, 4, 5, 2, 3},
            {1, 4, 3, 5, 2},
            {1, 4, 3, 2, 5},
            {1, 4, 2, 5, 3},
            {1, 4, 2, 3, 5},
            {1, 3, 5, 4, 2},
            {1, 3, 5, 2, 4},
            {1, 3, 4, 5, 2},
            {1, 3, 4, 2, 5},
            {1, 3, 2, 5, 4},
            {1, 3, 2, 4, 5},
            {1, 2, 5, 4, 3},
            {1, 2, 5, 3, 4},
            {1, 2, 4, 5, 3},
            {1, 2, 4, 3, 5},
            {1, 2, 3, 5, 4},
            {1, 2, 3, 4, 5}
    };
    float Array_Permutations_2[120][5] = {
            {5, 4, 3, 2, 1},
            {5, 4, 3, 1, 2},
            {5, 4, 2, 3, 1},
            {5, 4, 2, 1, 3},
            {5, 4, 1, 3, 2},
            {5, 4, 1, 2, 3},
            {5, 3, 4, 2, 1},
            {5, 3, 4, 1, 2},
            {5, 3, 2, 4, 1},
            {5, 3, 2, 1, 4},
            {5, 3, 1, 4, 2},
            {5, 3, 1, 2, 4},
            {5, 2, 4, 3, 1},
            {5, 2, 4, 1, 3},
            {5, 2, 3, 4, 1},
            {5, 2, 3, 1, 4},
            {5, 2, 1, 4, 3},
            {5, 2, 1, 3, 4},
            {5, 1, 4, 3, 2},
            {5, 1, 4, 2, 3},
            {5, 1, 3, 4, 2},
            {5, 1, 3, 2, 4},
            {5, 1, 2, 4, 3},
            {5, 1, 2, 3, 4},
            {4, 5, 3, 2, 1},
            {4, 5, 3, 1, 2},
            {4, 5, 2, 3, 1},
            {4, 5, 2, 1, 3},
            {4, 5, 1, 3, 2},
            {4, 5, 1, 2, 3},
            {4, 3, 5, 2, 1},
            {4, 3, 5, 1, 2},
            {4, 3, 2, 5, 1},
            {4, 3, 2, 1, 5},
            {4, 3, 1, 5, 2},
            {4, 3, 1, 2, 5},
            {4, 2, 5, 3, 1},
            {4, 2, 5, 1, 3},
            {4, 2, 3, 5, 1},
            {4, 2, 3, 1, 5},
            {4, 2, 1, 5, 3},
            {4, 2, 1, 3, 5},
            {4, 1, 5, 3, 2},
            {4, 1, 5, 2, 3},
            {4, 1, 3, 5, 2},
            {4, 1, 3, 2, 5},
            {4, 1, 2, 5, 3},
            {4, 1, 2, 3, 5},
            {3, 5, 4, 2, 1},
            {3, 5, 4, 1, 2},
            {3, 5, 2, 4, 1},
            {3, 5, 2, 1, 4},
            {3, 5, 1, 4, 2},
            {3, 5, 1, 2, 4},
            {3, 4, 5, 2, 1},
            {3, 4, 5, 1, 2},
            {3, 4, 2, 5, 1},
            {3, 4, 2, 1, 5},
            {3, 4, 1, 5, 2},
            {3, 4, 1, 2, 5},
            {3, 2, 5, 4, 1},
            {3, 2, 5, 1, 4},
            {3, 2, 4, 5, 1},
            {3, 2, 4, 1, 5},
            {3, 2, 1, 5, 4},
            {3, 2, 1, 4, 5},
            {3, 1, 5, 4, 2},
            {3, 1, 5, 2, 4},
            {3, 1, 4, 5, 2},
            {3, 1, 4, 2, 5},
            {3, 1, 2, 5, 4},
            {3, 1, 2, 4, 5},
            {2, 5, 4, 3, 1},
            {2, 5, 4, 1, 3},
            {2, 5, 3, 4, 1},
            {2, 5, 3, 1, 4},
            {2, 5, 1, 4, 3},
            {2, 5, 1, 3, 4},
            {2, 4, 5, 3, 1},
            {2, 4, 5, 1, 3},
            {2, 4, 3, 5, 1},
            {2, 4, 3, 1, 5},
            {2, 4, 1, 5, 3},
            {2, 4, 1, 3, 5},
            {2, 3, 5, 4, 1},
            {2, 3, 5, 1, 4},
            {2, 3, 4, 5, 1},
            {2, 3, 4, 1, 5},
            {2, 3, 1, 5, 4},
            {2, 3, 1, 4, 5},
            {2, 1, 5, 4, 3},
            {2, 1, 5, 3, 4},
            {2, 1, 4, 5, 3},
            {2, 1, 4, 3, 5},
            {2, 1, 3, 5, 4},
            {2, 1, 3, 4, 5},
            {1, 5, 4, 3, 2},
            {1, 5, 4, 2, 3},
            {1, 5, 3, 4, 2},
            {1, 5, 3, 2, 4},
            {1, 5, 2, 4, 3},
            {1, 5, 2, 3, 4},
            {1, 4, 5, 3, 2},
            {1, 4, 5, 2, 3},
            {1, 4, 3, 5, 2},
            {1, 4, 3, 2, 5},
            {1, 4, 2, 5, 3},
            {1, 4, 2, 3, 5},
            {1, 3, 5, 4, 2},
            {1, 3, 5, 2, 4},
            {1, 3, 4, 5, 2},
            {1, 3, 4, 2, 5},
            {1, 3, 2, 5, 4},
            {1, 3, 2, 4, 5},
            {1, 2, 5, 4, 3},
            {1, 2, 5, 3, 4},
            {1, 2, 4, 5, 3},
            {1, 2, 4, 3, 5},
            {1, 2, 3, 5, 4},
            {1, 2, 3, 4, 5}
    };

    float Array_Permutations_3[120][5] = {
            {5, 4, 3, 2, 1},
            {5, 4, 3, 1, 2},
            {5, 4, 2, 3, 1},
            {5, 4, 2, 1, 3},
            {5, 4, 1, 3, 2},
            {5, 4, 1, 2, 3},
            {5, 3, 4, 2, 1},
            {5, 3, 4, 1, 2},
            {5, 3, 2, 4, 1},
            {5, 3, 2, 1, 4},
            {5, 3, 1, 4, 2},
            {5, 3, 1, 2, 4},
            {5, 2, 4, 3, 1},
            {5, 2, 4, 1, 3},
            {5, 2, 3, 4, 1},
            {5, 2, 3, 1, 4},
            {5, 2, 1, 4, 3},
            {5, 2, 1, 3, 4},
            {5, 1, 4, 3, 2},
            {5, 1, 4, 2, 3},
            {5, 1, 3, 4, 2},
            {5, 1, 3, 2, 4},
            {5, 1, 2, 4, 3},
            {5, 1, 2, 3, 4},
            {4, 5, 3, 2, 1},
            {4, 5, 3, 1, 2},
            {4, 5, 2, 3, 1},
            {4, 5, 2, 1, 3},
            {4, 5, 1, 3, 2},
            {4, 5, 1, 2, 3},
            {4, 3, 5, 2, 1},
            {4, 3, 5, 1, 2},
            {4, 3, 2, 5, 1},
            {4, 3, 2, 1, 5},
            {4, 3, 1, 5, 2},
            {4, 3, 1, 2, 5},
            {4, 2, 5, 3, 1},
            {4, 2, 5, 1, 3},
            {4, 2, 3, 5, 1},
            {4, 2, 3, 1, 5},
            {4, 2, 1, 5, 3},
            {4, 2, 1, 3, 5},
            {4, 1, 5, 3, 2},
            {4, 1, 5, 2, 3},
            {4, 1, 3, 5, 2},
            {4, 1, 3, 2, 5},
            {4, 1, 2, 5, 3},
            {4, 1, 2, 3, 5},
            {3, 5, 4, 2, 1},
            {3, 5, 4, 1, 2},
            {3, 5, 2, 4, 1},
            {3, 5, 2, 1, 4},
            {3, 5, 1, 4, 2},
            {3, 5, 1, 2, 4},
            {3, 4, 5, 2, 1},
            {3, 4, 5, 1, 2},
            {3, 4, 2, 5, 1},
            {3, 4, 2, 1, 5},
            {3, 4, 1, 5, 2},
            {3, 4, 1, 2, 5},
            {3, 2, 5, 4, 1},
            {3, 2, 5, 1, 4},
            {3, 2, 4, 5, 1},
            {3, 2, 4, 1, 5},
            {3, 2, 1, 5, 4},
            {3, 2, 1, 4, 5},
            {3, 1, 5, 4, 2},
            {3, 1, 5, 2, 4},
            {3, 1, 4, 5, 2},
            {3, 1, 4, 2, 5},
            {3, 1, 2, 5, 4},
            {3, 1, 2, 4, 5},
            {2, 5, 4, 3, 1},
            {2, 5, 4, 1, 3},
            {2, 5, 3, 4, 1},
            {2, 5, 3, 1, 4},
            {2, 5, 1, 4, 3},
            {2, 5, 1, 3, 4},
            {2, 4, 5, 3, 1},
            {2, 4, 5, 1, 3},
            {2, 4, 3, 5, 1},
            {2, 4, 3, 1, 5},
            {2, 4, 1, 5, 3},
            {2, 4, 1, 3, 5},
            {2, 3, 5, 4, 1},
            {2, 3, 5, 1, 4},
            {2, 3, 4, 5, 1},
            {2, 3, 4, 1, 5},
            {2, 3, 1, 5, 4},
            {2, 3, 1, 4, 5},
            {2, 1, 5, 4, 3},
            {2, 1, 5, 3, 4},
            {2, 1, 4, 5, 3},
            {2, 1, 4, 3, 5},
            {2, 1, 3, 5, 4},
            {2, 1, 3, 4, 5},
            {1, 5, 4, 3, 2},
            {1, 5, 4, 2, 3},
            {1, 5, 3, 4, 2},
            {1, 5, 3, 2, 4},
            {1, 5, 2, 4, 3},
            {1, 5, 2, 3, 4},
            {1, 4, 5, 3, 2},
            {1, 4, 5, 2, 3},
            {1, 4, 3, 5, 2},
            {1, 4, 3, 2, 5},
            {1, 4, 2, 5, 3},
            {1, 4, 2, 3, 5},
            {1, 3, 5, 4, 2},
            {1, 3, 5, 2, 4},
            {1, 3, 4, 5, 2},
            {1, 3, 4, 2, 5},
            {1, 3, 2, 5, 4},
            {1, 3, 2, 4, 5},
            {1, 2, 5, 4, 3},
            {1, 2, 5, 3, 4},
            {1, 2, 4, 5, 3},
            {1, 2, 4, 3, 5},
            {1, 2, 3, 5, 4},
            {1, 2, 3, 4, 5}
    };
    // Bubble Sort
    vector<float> oprBubSort;
    vector<float> oprSelSort;
    vector<float> oprInsSort;

    for (int i = 0; i < 120; i++) {
        oprBubSort.push_back(BubbleSort(Array_Permutations[i], 5));
        oprSelSort.push_back(selectionSort(Array_Permutations_2[i], 5));
        oprInsSort.push_back(InsSort(Array_Permutations_3[i], 5));
        cout << "Complexity_Bub[" << i << "]->" << oprBubSort[i]
             << "\t\t" << "Complexity_Sel[" << i << "]->" << oprSelSort[i]
             << "\t\t" << "Complexity_Ins[" << i << "]->" << oprInsSort[i];
        cout << endl;
    }

    sort(oprBubSort.begin(), oprBubSort.end());
    sort(oprSelSort.begin(), oprSelSort.end());
    sort(oprInsSort.begin(), oprInsSort.end());

    vector<float> worst_cases;
    worst_cases.push_back(oprBubSort[oprBubSort.size() - 1]);
    worst_cases.push_back(oprSelSort[oprSelSort.size() - 1]);
    worst_cases.push_back(oprInsSort[oprInsSort.size() - 1]);

    vector<float> best_cases;
    best_cases.push_back(oprBubSort[0]);
    best_cases.push_back(oprSelSort[0]);
    best_cases.push_back(oprInsSort[0]);

    vector<float> average_cases;
    average_cases.push_back((oprBubSort[oprBubSort.size() - 1] + oprBubSort[0]) / 2);
    average_cases.push_back((oprSelSort[oprSelSort.size() - 1] + oprSelSort[0]) / 2);
    average_cases.push_back((oprInsSort[oprInsSort.size() - 1] + oprInsSort[0]) / 2);

    cout << "Best cases\n" << "Bubble Sort: " << best_cases[0]
         << "\tSelection Sort: " << best_cases[1]
         << "\tInsertion Sort: " << best_cases[2]

         << "\nAverage cases\n" << "Bubble Sort: " << average_cases[0]
         << "\tSelection Sort: " << average_cases[1]
         << "\tInsertion Sort: " << average_cases[2]

         << "\nWorst cases\n" << "Bubble Sort: " << worst_cases[0]
         << "\tSelection Sort: " << worst_cases[1]
         << "\tInsertion Sort: " << worst_cases[2];
   cout << endl;*/

    /*for(int i = 0; i < 120; i++) {
        for (int j = 0; j < 5; j++) {
            cout << Array_Permutations_2[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}
