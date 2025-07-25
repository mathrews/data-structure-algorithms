#include <algorithm>
#include <iostream>
#include <vector>

int sum(std::vector<int> *values) {
	if (values->empty()) {
		return 0;
	}

	int back = values->back();
	values->pop_back();
	return back + sum(values);
}

int leng(std::vector<std::string> *list, int *count) {
	if (list->empty()) {
		return 0;
	}

	int res = *count + 1;
	list->pop_back();

	return res + leng(list, count);
}

int mostGratter(std::vector<int> list, std::vector<int> *list_original) {
	if (list_original->size() == 0) {
		return 0;
	}

	if (list_original->size() == 1) {
		int elem = list_original->at(0);
		return elem;
	}

	if (list_original->size() == 2) {
		return list_original->at(0) > list_original->at(1) ? list_original->at(0) : list_original->at(1);
	}

	if (list.size() == 1) {
		return list[0];
	}


	if (list.back() < list[list.size() -2]) {
		list.pop_back();
	} else {
		list.erase(list.begin() + list.size() - 2);
	}

	return mostGratter(list, list_original);
}

int bin_search(std::vector<int> list, int element) {
	int baixo = 0;
	int alto = list.size() - 1;

	if (list.size() <= 2) {
		return list[0] == element ? list[0] : list[1];
	}

	int meio = (baixo + alto) / 2;
	int chute = list[meio];

	if (chute == element) {
		return chute;
	}

	if (chute > element) {
		list.erase(list.begin() + list.size() / 2, list.end());
	} else {
		list.erase(list.begin(), list.begin() + meio);
	}

	return bin_search(list, element);
}

int main(void)
{
	std::vector<int> values = {4, 4, 5, 5, 6, 7, 8, 9};

	int sum_res = sum(&values);
	std::cout << sum_res << "\n";

	std::vector<std::string> strings = {"aasdf", "asdfasdf", "asdfasdf"};

	int count = 0;
	int res = leng(&strings, &count);
	std::cout << res << "\n";

	std::vector<int> values2 = {1, 2, 4, 5, 3, 12, 234, 6};
	int gratter = mostGratter(values2, &values2);
	std::cout << gratter << "\n";

	std::sort(values2.begin(), values2.end());
	std::cout << bin_search(values2, 4);

	return 0;
}
