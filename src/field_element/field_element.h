
class FieldElement {
 private:
  int num_;
  int prime_;

 public:
  FieldElement(int num, int prime);
  FieldElement(const FieldElement& other);
  FieldElement& operator=(const FieldElement& other);
  bool operator==(const FieldElement& other) const;
  bool operator!=(const FieldElement& other) const;
  FieldElement operator+(const FieldElement& other) const;
  FieldElement operator-(const FieldElement& other) const;
  FieldElement operator*(const FieldElement& other) const;
  FieldElement pow(const int exponent) const;
  int num() const;
  int prime() const;
};