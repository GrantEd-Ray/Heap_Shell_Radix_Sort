#include <iostream>
#include <vector>
#include <string>

void shell_sort(std::vector<int>& mas)
{
    for (int d = mas.size() / 2; d > 0; d /= 2)
    {
        for (int i = d; i < mas.size(); ++i)
        {
            for (int j = i - d; j >= 0 && mas[j] > mas [j+d]; j -= d)
            {
                std::swap(mas[j], mas[j + d]);
            }
        }
    }
};

void radix_sort(std::vector<int>& mas)
{
    std::vector<std::vector<int>> temp;
    int max_num = mas[0];
    for (int i = 0; i < 10; i++)
        temp.push_back({});
    for (int i = 1; i < mas.size(); i++)
    {
        if (mas[i] > max_num)
            max_num = mas[i];
    }
    int max_length = std::to_string(max_num).length();

    for (int i = 0; i < max_length; i++)
    {
        for (int k = 0; k < mas.size(); k++)
        {
            int t_num = mas[k] / pow(10, i);
            temp[t_num % 10].push_back(mas[k]);
        }

        int j = 0;
        for (int k = 0; k < temp.size(); k++)
        {
            if (temp[k].empty() == false)
                for (int l = 0; l < temp[k].size(); l++)
                {
                    mas[j] = temp[k][l];
                    j++;
                }
            temp[k].clear();
        }
    }
}

void heapify(std::vector<int>& array,int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && array[l] > array[largest])
        largest = l;

    if (r < n && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(array[i], array[largest]);
        heapify(array, n ,largest);
    }
}

void heap_sort(std::vector<int>& mas)
{
    for (int i = mas.size() / 2 - 1; i >= 0; i--)
        heapify(mas, mas.size(), i);
    for (int i = mas.size() - 1; i >= 0; i--)
    {
        std::swap(mas[0], mas[i]);
        heapify(mas, i, 0);
    }
}

void print(std::vector<int>& mas)
{
    for (int i = 0; i < mas.size(); i++)
        std::cout << mas[i] << ' ';
    std::cout << std::endl;
}

int main() {
    std::vector<int> list = {1, 64564, 224, 5942, 471, 46184863, 3, 871, 1564, 12};

    std::vector<int> list1 = list;
    shell_sort(list1);
    print(list1);

    std::vector<int> list2 = list;
    radix_sort(list2);
    print(list2);

    std::vector<int> list3 = list;
    heap_sort(list3);
    print(list3);

    return 0;
}
