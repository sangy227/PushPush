#pragma once
#include <iostream>

namespace ya
{
    template <typename T>
    struct Node
    {
        Node()
            : mData(NULL)
            , mNext(nullptr)
            , mPrev(nullptr)
        {

        }
        Node(const T data)
            : mData(data)
            , mNext(nullptr)
            , mPrev(nullptr)
        {

        }
        ~Node()
        {

        }

        T mData;
        Node<T>* mNext;
        Node<T>* mPrev;
    };

    template <typename T>
    class list
    {
    public:
        class iterator
        {
        public:
            iterator()
                : mPtr(nullptr)
            {

            }
            iterator(const iterator& other)
                : mPtr(other.mPtr)
            {

            }
            iterator(Node<T>* ptr)
                : mPtr(ptr)
            {

            }
            Node<T>* getPtr() { return mPtr; }

            T& operator*()
            {
                if (mPtr != nullptr)
                    return mPtr->mData;
            }

            iterator& operator++() // 傈困
            {
                if (mPtr != nullptr &&
                    mPtr->mNext != nullptr)
                {
                    mPtr = mPtr->mNext;
                }

                return *this;
            }

            iterator& operator++(int)
            {
                iterator temp(*this);
                if (mPtr != nullptr &&
                    mPtr->mNext != nullptr)
                {
                    mPtr = mPtr->mNext;
                }

                return temp;
            }
            iterator& operator--()
            {
                //槛力
                if (mptr != nullptr &&
                    mPtr->mPrev != nullptr)
                {
                    mPtr = mPtr->mPrev;
                }

                return *this;
            }
            iterator& operator--(int)
            {
                //槛力
                iterator temp(*this);
                if (mptr != nullptr &&
                    mPtr->mPrev != nullptr)
                {
                    mPtr = mPtr->mPrev;
                }
                return temp;

            }
            iterator& operator=(iterator& other)
            {
                mPtr = other.mPtr;
                return *this;
            }

            bool operator!=(iterator& other)
            {
                return !(this->mPtr == other->mPtr);
            }
            bool operator==(iterator& other)
            {
                return (this->mPtr == other.mPtr);
            }
        private:
            Node<T>* mPtr;
        };

        list()
        {
            mfirst = new Node<T>();
            mlast = new Node<T>();

            mfirst->mNext = mlast;
            mfirst->mPrev = nullptr;

            mlast->mNext = nullptr;
            mlast->mPrev = mfirst;

            mCount = 0;
        }
        list(const list& other)
        {
            mfirst = other.mfirst;
            mlast = other.mlast;
            mCount = other.mCount;
        }
        ~list()
        {
            mCount = 0;
            while (mfirst != nullptr)
            {
                Node<T>* ptr = nullptr;
                ptr = mfirst;
                mfirst = mfirst->mNext;

                delete ptr;
                ptr = nullptr;
            }
        }

        size_t size() { return mCount; }
        bool empty() { return (mCount == 0 ? true : false); }

        iterator begin() const
        {
            return iterator(mfirst);
        }
        iterator end() const
        {
            return iterator(mlast);
        }

        void push_back(const T& data)
        {
            if (mCount == 0)
            {
                mfirst->mData = data;
                mCount++;
                return;
            }
            Node<T>* newNode = new Node<T>(data);
            Node<T>* lastPrev = mlast->mPrev;

            lastPrev->mNext = newNode;
            newNode->mPrev = lastPrev;

            newNode->mNext = mlast;
            mlast->mPrev = newNode;

            mCount++;
        }
        void push_front(const T& data)
        {
            // 槛力
            Node<T>* head = new Node<T>(data);


            head->mNext = mfirst;
            mfirst->mPrev = head;


            head->mPrev = nullptr;

            mCount--;

        }
        void pop_back()
        {
            Node<T>* to_delete = mlast->mPrev;

            mlast->mPrev = to_delete->mPrev;
            to_delete->mPrev->mNext = mlast;

            delete to_delete;
            to_delete = nullptr;
        }
        void pop_front()
        {
            Node<T>* fr = mfirst->mNext;
            mfirst->mNext = fr->mNext;

            fr = nullptr;


        }
        void clear()
        {
            Node<T>* buffer = mlast->mPrev;
            while (buffer != mfirst)
            {
                Node<T>* to_delete = buffer;
                buffer = buffer->mPrev;

                mlast->mPrev = to_delete->mPrev;
                to_delete->mPrev->mNext = mlast;

                delete to_delete;
                to_delete = nullptr;
            }

            mfirst->mData = NULL;
            mCount = 0;
        }

        iterator erase(iterator iter)
        {
            //槛力
        }

    private:
        size_t mCount;
        Node<T>* mfirst;
        Node<T>* mlast;
    };


}