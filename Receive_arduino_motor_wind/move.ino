void moving() {
  if (step1 != 0) {
    if (step1 < 0) {
      step1 += space;
      s1 += space;
      myservo.write(round(s1));
    } else if (step1 > 0) {
      step1 -= space;
      s1 -= space;
      myservo.write(round(s1));
    }
  }
}
