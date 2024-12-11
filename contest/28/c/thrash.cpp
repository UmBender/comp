if (v == 1) {
  if (i - 3 >= 0) {
    if (s[i - 1] == '0' && s[i - 2] == '1' && s[i - 3] == '1') {
      counter--;
    }
  }
  if (i - 2 >= 0 && i + 1 < s.size()) {
    if (s[i + 1] == '0' && s[i - 1] == '1' && s[i - 2] == '1') {
      counter--;
    }
  }
  if (i + 3 < s.size()) {
    if (s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
      counter++;
    }
  }
  if (i + 2 < s.size() && i - 1 >= 0) {
    if (s[i - 1] == '1' && s[i + 1] == '0' && s[i + 2] == '0') {
      counter++;
    }
  }
}
if (v == 0) {
  if (i + 3 < s.size()) {
    if (s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
      counter--;
    }
  }
  if (i + 2 < s.size() && i - 1 >= 0) {
    if (s[i - 1] == '1' && s[i + 1] == '0' && s[i + 2] == '0') {
      counter--;
    }
  }
  if (i - 3 >= 0) {
    if (s[i - 1] == '0' && s[i - 2] == '1' && s[i - 3] == '1') {
      counter++;
    }
  }
  if (i - 2 >= 0 && i + 1 < s.size()) {
    if (s[i + 1] == '0' && s[i - 1] == '1' && s[i - 2] == '1') {
      counter++;
    }
  }
}
s[i] = v;
