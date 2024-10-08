#pragma once

#include<memory>

namespace sylar
{

    template<class T, class X, int N>
    T& GetInstanceX()
    {
        static T v;
        return v;
    }

    template<class T, class X, int N>
    std::shared_ptr<T> GetInstancePrt()
    {
        static std::shared_ptr<T> v(new T);
        return v;
    }

    /**
     * @brief 单例模式封装类
     * @details T 类型
     *          X 为了创造多个实例对应的Tag
     *          N 同一个Tag创造多个实例索引
     */
    template<class T, class X = void, int N =0>
    class Singleton
    {
    public:
        static T* GetInstancePrt()
        {
            static T v;
            return &v;
        }

        static T* GetInstance() 
        {
            static T v;
            return &v;
        }
    };

    /**
     * @brief 单例模式智能指针封装类
     * @details T 类型
     *          X 为了创造多个实例对应的Tag
     *          N 同一个Tag创造多个实例索引
     */
    template<class T, class X = void, int N = 0>
    class SingletonPrt
    {
    public:
        /**
         * @brief 返回单例智能指针
         */
        static std::shared_ptr<T> GetInstance()
        {
            static std::shared_ptr<T> v(new T);
            return v;
        }
    };
    
}