template <class T>
class TMyVector
{
public:
    //
private:
    T* ReservArr_;
    int CurrentSize_;
    int ReservSize_;
    int MagFactor_ = 2;
public:
    TMyVector(int size) {
        ReservSize_ = size;
        CurrentSize_ = 0;
        ReservArr_ = new T(ReservSize_);
    }

    TMyVector() : TMyVector(0) {}

    ~TMyVector() {
        delete[] ReservArr_;
    }   
};