#include <iostream>
#include <vector>

using namespace std;

void text_justification(vector<string> words, int maxWidth) {
  // Create an empty vector to store the justified lines.
  vector<string> lines;

  // Iterate over the words.
  for (int i = 0; i < words.size(); i++) {
    // Initialize the current line.
    string line = "";

    // Keep adding words to the current line until it reaches the maximum width.
    int j = i;
    while (j < words.size() && line.length() + words[j].length() <= maxWidth) {
      line += words[j] + " ";
      j++;
    }

    // If the current line is not the last line, then add spaces to it.
    if (j < words.size()) {
      int num_spaces = maxWidth - line.length();
      int num_words = j - i;
      int space_per_word = num_spaces / num_words;
      int extra_spaces = num_spaces % num_words;

      for (int k = 0; k < num_words - 1; k++) {
        line += " " + string(space_per_word, ' ');
      }

      if (extra_spaces > 0) {
        line += string(extra_spaces, ' ');
      }
    }

    // Add the current line to the output vector.
    lines.push_back(line);
  }

  // Print the justified lines.
  for (string line : lines) {
    cout << line << endl;
  }
}

int main() {
  // Get the words and maximum width from the user.
  vector<string> words;
  int maxWidth;
  cin >> words;
  cin >> maxWidth;

  // Justify the text.
  text_justification(words, maxWidth);

  return 0;
}
