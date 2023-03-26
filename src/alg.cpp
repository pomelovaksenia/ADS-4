// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[j] + arr[i] == value) {
        counter += 1;
      }
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        counter += 1;
      }
    }
  }
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i;
    right = len;
    while (left < right - 1) {
      int middle = (left + right) / 2;
      if (arr[i] + arr[middle] == value) {
        counter += 1;
        int newMiddle = middle + 1;
        while (arr[i] + arr[newMiddle] == value && newMiddle < right) {
          counter += 1;
          newMiddle += 1;
        }
        newMiddle = center - 1;
        while (arr[i] + arr[newMiddle] == value && newMiddle > left) {
          counter += 1;
          newMiddle -= 1;
        }
        break;
      }
      if (arr[i] + arr[middle] > value) {
        right = middle;
      } else {
        left = middle;
      }
    }
  }
  return counter;
}
