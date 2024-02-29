const int nom[4] = {1, 2, 5, 10};
int moneys[4] = {10, 10, 10, 10};
int n = 0, maxF = 0;

int getValue(int arr[4]) {
  int s = 0;
  for (int i=0; i<4; i++) {
    s += arr[i]*nom[i];
  } return s;
}

void setup() {
  Serial.begin(9600);
  
  n = getValue(moneys);
  for (int m: moneys) {
    maxF += m;
  }

  int F[n+1][4] = {{0, 0, 0, 0}};
  for (int k=1; k<=n; k++) {
    int x[2] = {-1, -1}, minF = maxF, newF = 0;

    for (int i=0; i<4; i++) {
      int a = nom[i];
      if ((k-a >= 0)and(moneys[i]-F[k-a][i] > 0)and(k-a == getValue(F[k-a]))) {
        newF = 1;
        for (int m: F[k-a]) {
          newF += m;
        }
        if (newF < minF) {
          minF = newF;
          x[0] = i; x[1] = a;
        }
      }
    }

    if (x[0] == -1) {
      for (int i=1; i<4; i++) {
        int a = nom[i];
        for (int j=1; j<a; j++) {
          if ((k-a+j >= 0)and(moneys[i] > F[k-a+j][i])) {
            newF = 1;
            for (int m: F[k-a+j]) {
              newF += m;
            }
            if (newF < minF) {
              minF = newF;
              x[0] = i; x[1] = a-j;
            }
          }
        }
      }
    }

    if (x[0] != -1) {
      for (int i=0; i<4; i++) {
        F[k][i] = F[k-x[1]][i];
      } F[k][x[0]] += 1;
    } else {
      for (int i=0; i<4; i++) {
        F[k][i] = moneys[i];
      }
    }

//    Serial.print(k); Serial.print("р. - ");
//    for (int m: F[k]) {
//      Serial.print(m); Serial.print(" ");
//    } Serial.println();
  }
  Serial.println("That all!");
  
}

void loop() {
}
