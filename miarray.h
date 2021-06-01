#ifndef MIARRAY_H
#define MIARRAY_H

#include <QMessageBox>

template <class T>
class MiArray
{
public:
    explicit MiArray() { m_size=0; }
    virtual ~MiArray() { destroy(); }

    int size() const{
        return m_size;
    }
    int indexOf(const T &arg) const {
        for (int i = 0; i < m_size; ++i) {
            if (arg == contenido[i])
                return i;
        }
        return -1;
    }
    void append(const T &arg) {
        T *ptr = new T(arg);
        contenido.push_back(ptr);
        ++index_ult;
        ++m_size;
    }
    void clear(){
        index_ult=0;
        m_size = 0; contenido.clear();
    }
    void replace (const int &i, const T *value) {
        contenido[i] = value;
    }
    void removeAt(const int &i) {
        assert(i >=0 && i < m_size);
        for (int idx = i; idx < m_size - 2; ++idx) {
            contenido[i] = contenido[i+1];
        }
        delete contenido[m_size-1];
        contenido.erase(i);//quizas no es i sino la posicion del iterador
        --m_size;
    }
    void swap (const int &i, const int &j){
        T *temp = contenido[i];
        contenido[i] = contenido[j];
        contenido[j] = temp;
    }
    T *operator[](const int &i) {
        assert(0 <= i && i < m_size);
        return (contenido[i]);
    }
    const T &at(const int &indice) const{
        assert(0 <= indice && indice < m_size);
        return (*(contenido[indice]));
    }
    MiArray &operator=(const MiArray &a){
        if (&a != this){
            int i = 0;
            destroy();
            for (auto ptr: a.contenido) {
                appendptr(ptr);
                ++i;
            }
        }
        return (*this);
    }

private:
    int m_size = 0,
        index_ult=0;

    void appendptr(T* ptr){
        contenido.push_back(ptr);
        ++m_size;
    }
    /**
     * @brief es para liberar todos los punteros asignados
     */
    void destroy(){        
        for (unsigned int i = 0; i < contenido.size(); ++i) {
            delete contenido[i];
        }
        contenido.clear();
        m_size=0;
    }
protected:
    std::vector<T*> contenido;
};

#endif // MIARRAY_H
