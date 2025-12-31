#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Funkcja pomocnicza do wyświetlania listy
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Funkcja pomocnicza do dodawania na koniec (do testów)
Node* insertBack(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) return newNode;
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// ============================================================================
// POZIOM 1: ŁATWY
// ============================================================================

// TODO 1: Zaimplementuj funkcję wstawiającą węzeł na pozycji index (0-based)
// Przypadki:
// - index = 0: wstaw na początek
// - index >= długość listy: wstaw na koniec
// - index w środku: przejdź do pozycji index-1 i wstaw
// Funkcja zwraca nowy head
Node* insertAt(Node* head, int value, int index) {
    // UZUPEŁNIJ KOD
}

// TODO 2: Zaimplementuj funkcję usuwającą węzeł na pozycji index (0-based)
// Przypadki:
// - Lista pusta: zwróć nullptr
// - index = 0: usuń head
// - index >= długość listy: nie rób nic
// - index w środku: przejdź do pozycji index-1 i usuń następny węzeł
// Funkcja zwraca nowy head
Node* deleteAt(Node* head, int index) {
    // UZUPEŁNIJ KOD
}

// TODO 3: Zaimplementuj funkcję zliczającą wystąpienia wartości w liście
// Przejdź przez listę i zlicz ile razy występuje podana wartość
int countOccurrences(Node* head, int value) {
    // UZUPEŁNIJ KOD
}

// ============================================================================
// POZIOM 2: ŚREDNI
// ============================================================================

// TODO 4: Zaimplementuj funkcję odwracającą listę
// Zmień kierunek wszystkich wskaźników next
// Możesz użyć podejścia iteracyjnego (3 wskaźniki: prev, current, next)
// Funkcja zwraca nowy head (poprzedni ostatni węzeł)
Node* reverse(Node* head) {
    // UZUPEŁNIJ KOD
}

// TODO 5: Zaimplementuj funkcję zwracającą środkowy węzeł listy
// Użyj techniki dwóch wskaźników: slow (1 krok) i fast (2 kroki)
// Gdy fast dotrze do końca, slow będzie w środku
// Dla nieparzystej długości zwróć dokładnie środkowy element
// Dla parzystej długości zwróć drugi z dwóch środkowych
Node* getMiddle(Node* head) {
    // UZUPEŁNIJ KOD
}

// TODO 6: Zaimplementuj funkcję dzielącą listę na pozycji index
// Zwraca drugą część listy (od index włącznie)
// Pierwsza część zostaje w oryginalnej liście (head)
// Przykład: lista 1->2->3->4->5, splitAt(head, 3) zwraca 4->5, a head to 1->2->3
Node* splitAt(Node* head, int index) {
    // UZUPEŁNIJ KOD
}

// ============================================================================
// POZIOM 3: TRUDNY
// ============================================================================

// TODO 7: Zaimplementuj funkcję scalającą dwie posortowane listy w jedną posortowaną
// list1 i list2 są już posortowane rosnąco
// Zwróć nową posortowaną listę zawierającą wszystkie elementy
// Możesz modyfikować istniejące węzły (nie twórz nowych)
Node* mergeSortedLists(Node* list1, Node* list2) {
    // UZUPEŁNIJ KOD
}

// TODO 8: Zaimplementuj funkcję sortującą listę algorytmem merge sort
// Kroki:
// 1. Jeśli lista ma 0 lub 1 element, jest już posortowana
// 2. Podziel listę na dwie połowy (użyj getMiddle i splitAt)
// 3. Rekurencyjnie posortuj obie połowy
// 4. Scal posortowane połowy (użyj mergeSortedLists)
Node* mergeSort(Node* head) {
    // UZUPEŁNIJ KOD
}

// TODO 9: Zaimplementuj funkcję wykrywającą cykl w liście
// Użyj algorytmu Floyd'a (tortoise and hare):
// - Dwa wskaźniki: slow (1 krok) i fast (2 kroki)
// - Jeśli się spotkają, lista ma cykl
// - Jeśli fast dotrze do nullptr, nie ma cyklu
bool hasCycle(Node* head) {
    // UZUPEŁNIJ KOD
}


#ifndef CATCH_CONFIG_MAIN
int test() {
    // ========================================================================
    // TESTY POZIOMU 1
    // ========================================================================
    
    cout << "=== POZIOM 1: LATWY ===\n\n";
    
    // Test 1: insertAt
    cout << "Test 1: insertAt\n";
    Node* head1 = nullptr;
    head1 = insertBack(head1, 10);
    head1 = insertBack(head1, 20);
    head1 = insertBack(head1, 40);
    cout << "Lista poczatkowa: ";
    displayList(head1);
    
    head1 = insertAt(head1, 5, 0);  // wstaw na początek
    cout << "Po insertAt(5, 0): ";
    displayList(head1);
    
    head1 = insertAt(head1, 30, 3);  // wstaw w środek
    cout << "Po insertAt(30, 3): ";
    displayList(head1);
    
    head1 = insertAt(head1, 50, 10);  // wstaw na koniec (index > długość)
    cout << "Po insertAt(50, 10): ";
    displayList(head1);
    /*
    Oczekiwany wynik:
    Lista poczatkowa: 10 -> 20 -> 40 -> nullptr
    Po insertAt(5, 0): 5 -> 10 -> 20 -> 40 -> nullptr
    Po insertAt(30, 3): 5 -> 10 -> 20 -> 30 -> 40 -> nullptr
    Po insertAt(50, 10): 5 -> 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
    */
    cout << endl;
    
    // Test 2: deleteAt
    cout << "Test 2: deleteAt\n";
    cout << "Lista przed usunieciem: ";
    displayList(head1);
    
    head1 = deleteAt(head1, 0);  // usuń początek
    cout << "Po deleteAt(0): ";
    displayList(head1);
    
    head1 = deleteAt(head1, 2);  // usuń środek
    cout << "Po deleteAt(2): ";
    displayList(head1);
    
    head1 = deleteAt(head1, 10);  // usuń poza zakresem (nic się nie stanie)
    cout << "Po deleteAt(10): ";
    displayList(head1);
    /*
    Oczekiwany wynik:
    Lista przed usunieciem: 5 -> 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
    Po deleteAt(0): 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
    Po deleteAt(2): 10 -> 20 -> 40 -> 50 -> nullptr
    Po deleteAt(10): 10 -> 20 -> 40 -> 50 -> nullptr
    */
    cout << endl;
    
    // Test 3: countOccurrences
    cout << "Test 3: countOccurrences\n";
    Node* head2 = nullptr;
    head2 = insertBack(head2, 10);
    head2 = insertBack(head2, 20);
    head2 = insertBack(head2, 10);
    head2 = insertBack(head2, 30);
    head2 = insertBack(head2, 10);
    cout << "Lista: ";
    displayList(head2);
    cout << "Liczba wystapien 10: " << countOccurrences(head2, 10) << endl;
    cout << "Liczba wystapien 20: " << countOccurrences(head2, 20) << endl;
    cout << "Liczba wystapien 99: " << countOccurrences(head2, 99) << endl;
    /*
    Oczekiwany wynik:
    Lista: 10 -> 20 -> 10 -> 30 -> 10 -> nullptr
    Liczba wystapien 10: 3
    Liczba wystapien 20: 1
    Liczba wystapien 99: 0
    */
    cout << endl;
    
    // ========================================================================
    // TESTY POZIOMU 2
    // ========================================================================
    
    cout << "=== POZIOM 2: SREDNI ===\n\n";
    
    // Test 4: reverse
    cout << "Test 4: reverse\n";
    Node* head3 = nullptr;
    head3 = insertBack(head3, 1);
    head3 = insertBack(head3, 2);
    head3 = insertBack(head3, 3);
    head3 = insertBack(head3, 4);
    head3 = insertBack(head3, 5);
    cout << "Lista przed odwroceniem: ";
    displayList(head3);
    
    head3 = reverse(head3);
    cout << "Lista po odwroceniu: ";
    displayList(head3);
    /*
    Oczekiwany wynik:
    Lista przed odwroceniem: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Lista po odwroceniu: 5 -> 4 -> 3 -> 2 -> 1 -> nullptr
    */
    cout << endl;
    
    // Test 5: getMiddle
    cout << "Test 5: getMiddle\n";
    Node* head4 = nullptr;
    head4 = insertBack(head4, 1);
    head4 = insertBack(head4, 2);
    head4 = insertBack(head4, 3);
    head4 = insertBack(head4, 4);
    head4 = insertBack(head4, 5);
    cout << "Lista (nieparzysta dlugosc): ";
    displayList(head4);
    Node* middle = getMiddle(head4);
    cout << "Srodkowy element: " << (middle ? middle->data : -1) << endl;
    
    Node* head5 = nullptr;
    head5 = insertBack(head5, 1);
    head5 = insertBack(head5, 2);
    head5 = insertBack(head5, 3);
    head5 = insertBack(head5, 4);
    cout << "Lista (parzysta dlugosc): ";
    displayList(head5);
    middle = getMiddle(head5);
    cout << "Srodkowy element: " << (middle ? middle->data : -1) << endl;
    /*
    Oczekiwany wynik:
    Lista (nieparzysta dlugosc): 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Srodkowy element: 3
    Lista (parzysta dlugosc): 1 -> 2 -> 3 -> 4 -> nullptr
    Srodkowy element: 3
    */
    cout << endl;
    
    // Test 6: splitAt
    cout << "Test 6: splitAt\n";
    Node* head6 = nullptr;
    head6 = insertBack(head6, 1);
    head6 = insertBack(head6, 2);
    head6 = insertBack(head6, 3);
    head6 = insertBack(head6, 4);
    head6 = insertBack(head6, 5);
    cout << "Lista przed podzialem: ";
    displayList(head6);
    
    Node* secondPart = splitAt(head6, 3);
    cout << "Pierwsza czesc: ";
    displayList(head6);
    cout << "Druga czesc: ";
    displayList(secondPart);
    /*
    Oczekiwany wynik:
    Lista przed podzialem: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Pierwsza czesc: 1 -> 2 -> 3 -> nullptr
    Druga czesc: 4 -> 5 -> nullptr
    */
    cout << endl;
    
    // ========================================================================
    // TESTY POZIOMU 3
    // ========================================================================
    
    cout << "=== POZIOM 3: TRUDNY ===\n\n";
    
    // Test 7: mergeSortedLists
    cout << "Test 7: mergeSortedLists\n";
    Node* list1 = nullptr;
    list1 = insertBack(list1, 1);
    list1 = insertBack(list1, 3);
    list1 = insertBack(list1, 5);
    cout << "Lista 1: ";
    displayList(list1);
    
    Node* list2 = nullptr;
    list2 = insertBack(list2, 2);
    list2 = insertBack(list2, 4);
    list2 = insertBack(list2, 6);
    cout << "Lista 2: ";
    displayList(list2);
    
    Node* merged = mergeSortedLists(list1, list2);
    cout << "Lista po scaleniu: ";
    displayList(merged);
    /*
    Oczekiwany wynik:
    Lista 1: 1 -> 3 -> 5 -> nullptr
    Lista 2: 2 -> 4 -> 6 -> nullptr
    Lista po scaleniu: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr
    */
    cout << endl;
    
    // Test 8: mergeSort
    cout << "Test 8: mergeSort\n";
    Node* head7 = nullptr;
    head7 = insertBack(head7, 64);
    head7 = insertBack(head7, 34);
    head7 = insertBack(head7, 25);
    head7 = insertBack(head7, 12);
    head7 = insertBack(head7, 22);
    head7 = insertBack(head7, 11);
    head7 = insertBack(head7, 90);
    cout << "Lista przed sortowaniem: ";
    displayList(head7);
    
    head7 = mergeSort(head7);
    cout << "Lista po sortowaniu: ";
    displayList(head7);
    /*
    Oczekiwany wynik:
    Lista przed sortowaniem: 64 -> 34 -> 25 -> 12 -> 22 -> 11 -> 90 -> nullptr
    Lista po sortowaniu: 11 -> 12 -> 22 -> 25 -> 34 -> 64 -> 90 -> nullptr
    */
    cout << endl;
    
    // Test 9: hasCycle
    cout << "Test 9: hasCycle\n";
    
    // Lista bez cyklu
    Node* head8 = nullptr;
    head8 = insertBack(head8, 1);
    head8 = insertBack(head8, 2);
    head8 = insertBack(head8, 3);
    head8 = insertBack(head8, 4);
    cout << "Lista bez cyklu: 1 -> 2 -> 3 -> 4 -> nullptr" << endl;
    cout << "Czy ma cykl? " << (hasCycle(head8) ? "TAK" : "NIE") << endl;
    
    // Lista z cyklem (tworzymy ręcznie)
    Node* head9 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    head9->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  // cykl: 4 wskazuje na 2
    cout << "Lista z cyklem: 1 -> 2 -> 3 -> 4 -> 2 (cykl)" << endl;
    cout << "Czy ma cykl? " << (hasCycle(head9) ? "TAK" : "NIE") << endl;
    /*
    Oczekiwany wynik:
    Lista bez cyklu: 1 -> 2 -> 3 -> 4 -> nullptr
    Czy ma cykl? NIE
    Lista z cyklem: 1 -> 2 -> 3 -> 4 -> 2 (cykl)
    Czy ma cykl? TAK
    */
    
    return 0;
}

#endif // CATCH_CONFIG_MAIN
