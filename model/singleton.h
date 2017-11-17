#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
class Singleton
{
    static T* m_instance;

    // Unimplemented to force uniqueness
    Singleton(const Singleton<T> &) = delete;
    Singleton& operator=(const Singleton<T> &) = delete;

protected:
    Singleton() { }

public:
    static T& instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new T();
        }

        return *m_instance;
    }

    static T* instancePtr()
    {
        if (m_instance == nullptr)
        {
            m_instance = new Singleton<T>();
        }

        return *m_instance;
    }
};

template<typename T>
T* Singleton<T>::m_instance = nullptr;

#endif
