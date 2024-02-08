#include <field_element/field_element.h>
#include <util/uint256.h>

using namespace std;

// P is the prime number 2**256 - 2**32 - 977
static const uint256 P("11579208923731619542357098500868790785326998466564056"
                       "4039457584007913129639747");

class S256Field : public FieldElement {
private:
  uint256 num_;
  uint256 prime_;

public:
  S256Field(const uint256 &num);
};