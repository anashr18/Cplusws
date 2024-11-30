class Integer
{
public:
    Integer(int value);
    int getValue() const;
    void setValue(int value);
    ~Integer();
    // copy constructor
    Integer(const Integer &other);
    // assignment copy construcor and operator overloading
    Integer &operator=(const Integer &other);
    Integer(Integer &&other);
    // Integer &operator=(const Integer &&other);

private:
    int *m_pInt;
};
