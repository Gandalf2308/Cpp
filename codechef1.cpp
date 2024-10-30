#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // Min-heap based on frequency
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->data] = str;
    }

    generateCodes(root->left, str + "0", huffmanCodes);
    generateCodes(root->right, str + "1", huffmanCodes);
}

// Build Huffman Tree
Node* buildHuffmanTree(const unordered_map<char, int>& frequency) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (const auto& pair : frequency) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top(); // Root of the Huffman Tree
}

// Compress the text file
void compress(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    unordered_map<char, int> frequency;
    char ch;

    // Calculate frequency of each character
    while (inFile.get(ch)) {
        frequency[ch]++;
    }
    inFile.close();

    // Build Huffman Tree
    Node* root = buildHuffmanTree(frequency);

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Write compressed data to the output file
    ofstream outFile(outputFile, ios::binary);
    inFile.open(inputFile);
    string compressedData = "";

    while (inFile.get(ch)) {
        compressedData += huffmanCodes[ch];
    }
    inFile.close();

    // Convert binary string to bytes and write to file
    for (size_t i = 0; i < compressedData.size(); i += 8) {
        string byteString = compressedData.substr(i, 8);
        if (byteString.size() < 8) {
            byteString.append(8 - byteString.size(), '0'); // Pad with zeros
        }
        char byte = static_cast<char>(stoi(byteString, nullptr, 2));
        outFile.put(byte);
    }
    outFile.close();

    cout << "File compressed successfully!" << endl;
}

// Decompress the compressed file
void decompress(const string& inputFile, const string& outputFile, Node* root) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile);
    string binaryString = "";
    char ch;

    // Read bytes and convert to binary string
    while (inFile.get(ch)) {
        for (int i = 7; i >= 0; i--) {
            binaryString += ((ch >> i) & 1) ? '1' : '0';
        }
    }
    inFile.close();

    // Traverse the Huffman Tree to decode the binary string
    Node* current = root;
    for (char bit : binaryString) {
        current = (bit == '0') ? current->left : current->right;

        // If we reach a leaf node, write the character to the output file
        if (current->left == nullptr && current->right == nullptr) {
            outFile.put(current->data);
            current = root; // Reset to the root for the next character
        }
    }
    outFile.close();

    cout << "File decompressed successfully!" << endl;
}

// Main function to demonstrate compression and decompression
int main() {
    string inputFile = "input.txt"; // Input file to compress
    string compressedFile = "compressed.bin"; // Compressed output file
    string decompressedFile = "decompressed.txt"; // Decompressed output file

    // Compress the file
    compress(inputFile, compressedFile);

    // Build Huffman Tree again for decompression
    unordered_map<char, int> frequency;
    ifstream inFile(inputFile);
    char ch;
    while (inFile.get(ch)) {
        frequency[ch]++;
    }
    inFile.close();
    Node* root = buildHuffmanTree(frequency);

    // Decompress the file
    decompress(compressedFile, decompressedFile, root);

    return 0;
}