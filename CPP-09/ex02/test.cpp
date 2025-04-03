#include <iostream>
#include <vector>
#include <algorithm> // Pour std::sort

// Fusion optimisée en minimisant les comparaisons
void merge(std::vector<int>& sorted, const std::vector<int>& to_merge) {
    std::vector<int> temp;
    size_t i = 0, j = 0;

    while (i < sorted.size() && j < to_merge.size()) {
        if (sorted[i] < to_merge[j]) {
            temp.push_back(sorted[i++]);
        } else {
            temp.push_back(to_merge[j++]);
        }
    }

    while (i < sorted.size()) temp.push_back(sorted[i++]);
    while (j < to_merge.size()) temp.push_back(to_merge[j++]);

    sorted = std::move(temp);
}

// Ford-Johnson Sort
std::vector<int> fordJohnsonSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    std::vector<int> sorted;

    // Étape 1 : Trier les paires d'éléments et former une base triée
    std::vector<int> remaining;
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
        sorted.push_back(arr[i + 1]); // Garder le plus grand dans la liste triée
        remaining.push_back(arr[i]);  // Garder le plus petit pour l'insertion ultérieure
    }
    if (arr.size() % 2 == 1) {
        remaining.push_back(arr.back()); // Si un élément seul reste, on le garde pour plus tard
    }

    // Étape 2 : Trier la base triée
    std::sort(sorted.begin(), sorted.end());

    // Étape 3 : Insérer intelligemment les éléments restants
    for (int num : remaining) {
        auto pos = std::lower_bound(sorted.begin(), sorted.end(), num);
        sorted.insert(pos, num);
    }

    return sorted;
}

// Test du programme
int main() {
    std::vector<int> arr = {9, 3, 7, 5, 1, 8, 4, 6, 2};
    std::vector<int> sorted = fordJohnsonSort(arr);

    std::cout << "Tableau trié : ";
    for (int num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
