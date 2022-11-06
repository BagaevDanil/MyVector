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
        ReservArr_ = new T[ReservSize_];
    }

    TMyVector() : TMyVector(0) {}

    ~TMyVector() {
        delete[] ReservArr_;
    }
public:
    int GetSize();
    int GetReservSize();
    void PushBack(T value);
    void PushForward(T value);
    void Insert(int pos, T value);
    void Reserv(int newSize);
    int GetValue(int ind);
    void Delete(int pos);
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
    Insert(CurrentSize_, value);
}

template <class T>
void TMyVector<T>::PushForward(T value) {
    Insert(0, value);
}

template <class T>
void TMyVector<T>::Reserv(int newSize) {
    if (newSize < CurrentSize_) {
        // Erorr
    }
    T* newReservArr = new T[newSize];

    for (int i = 0; i < CurrentSize_; i++) {
        newReservArr[i] = ReservArr_[i];
    }

    delete[] ReservArr_;
    ReservSize_ = newSize;
    ReservArr_ = newReservArr;
}

template <class T>
int TMyVector<T>::GetValue(int ind) {
    if (ind >= CurrentSize_) {
        // Error
    }
    return ReservArr_[ind];
}

template <class T>
void TMyVector<T>::Insert(int pos, T value) {
    if (pos > CurrentSize_ || pos < 0) {
        // Error
    }
    if (ReservSize_ <= CurrentSize_) {
        Reserv(ReservSize_ * MagFactor_);
    }
    for (int i = CurrentSize_; i > pos; i--) {
        ReservArr_[i] = ReservArr_[i - 1];
    }
    CurrentSize_++;
    ReservArr_[pos] = value;
}

template <class T>
void TMyVector<T>::Delete(int pos) {
    if (pos > CurrentSize_ || pos < 0) {
        // Error
    }
    for (int i = pos; i < CurrentSize_ - 1; i++) {
        ReservArr_[i] = ReservArr_[i + 1];
    }
    CurrentSize_--;
    if (ReservSize_ > CurrentSize_ * MagFactor_) {
        Reserv(CurrentSize_ * MagFactor_);
    }
}