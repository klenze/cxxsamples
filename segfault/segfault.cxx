void A(int* p)
{
  // do something illegal:
  (*p)++;
}
void B(int * a)
{
  A(a);
}

void C(bool crash=1)
{
  int* p=nullptr;
  int i{};
  if (!crash)
    p=&i;
  B(p);
}
int main()
{
  C(1);
}

