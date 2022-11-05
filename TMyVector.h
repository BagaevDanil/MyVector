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
public:
    int GetSize();
    int GetReservSize();
    void PushBack(T value);
    void Reserv(int newSize);
    int GetValue(int ind);
};

// Realization
template <class T>
int TMyVector<T>::GetSize() {
    return CurrentSize_;
}

template <class T>
int TMyVector<T>::GetReservSize() {
    return ReservSize_;
}

template <class T>
void TMyVector<T>::PushBack(T value) {
    if (ReservSize_ <= CurrentSize_) {
        Reserv(ReservSize_ * MagFactor_);
    }
    ReservArr_[CurrentSize_++] = value;
}

template <class T>
void TMyVector<T>::Reserv(int newSize) {
    if (newSize < CurrentSize_) {
        // Erorr
    }
    T* newReservArr = new T(newSize);

    for (int i = 0; i < CurrentSize_; i++) {
        newReservArr[i] = ReservArr_[i];
    }

    delete[] ReservArr_;
    ReservArr_ = newReservArr;
    
}

template <class T>
int TMyVector<T>::GetValue(int ind) {
    if (ind >= CurrentSize_) {
        // Error
    }
    return ReservArr_[ind];
}