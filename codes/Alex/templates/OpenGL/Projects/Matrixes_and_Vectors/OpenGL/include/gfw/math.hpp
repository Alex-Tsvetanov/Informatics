#pragma once
#include <cmath>
#include <cstddef>

#include "gfw/common.hpp"

namespace gfw{

#define GFW__VEC_COMMON \
	GFW__INLINE value_type &operator[](size_t i) noexcept{ \
		return data[i]; \
	} \
	GFW__INLINE value_type operator[](size_t i) const noexcept{ \
		return data[i]; \
	} \
	GFW__INLINE value_type len2() const noexcept{ \
		value_type res=data[0]*data[0]; \
		for(size_t i=1;i<size;i++) res+=data[i]*data[i]; \
		return res; \
	} \
	GFW__INLINE value_type len() const noexcept{ \
		return std::sqrt(len()); \
	} \
	GFW__INLINE Vec normal() const noexcept{ \
		return (*this)/len(); \
	} \
	GFW__INLINE Vec()=default; \
	GFW__INLINE Vec(const Vec&)=default; \
	GFW__INLINE Vec(Vec&&)=default; \
	template<class T2> \
	GFW__INLINE explicit Vec(const Vec<T2,size> &b) noexcept{ \
		for(size_t i=0;i<size;i++) data[i]=b[i]; \
		return; \
	}

template<class T, size_t N>
struct Vec;

template<class T, size_t N>
GFW__INLINE Vec<T,N> operator+(const Vec<T,N> &a, const Vec<T,N> &b) noexcept{
	for(size_t i=0;i<N;i++) a[i]+=b[i];
	return a;
}

template<class T, size_t N>
GFW__INLINE Vec<T,N> &operator+=(Vec<T,N> &a, const Vec<T,N> &b) noexcept{
	for(size_t i=0;i<N;i++) a[i]+=b[i];
	return a;
}

template<class T, size_t N>
GFW__INLINE Vec<T,N> operator-(const Vec<T,N> &a, const Vec<T,N> &b) noexcept{
	for(size_t i=0;i<N;i++) a[i]-=b[i];
	return a;
}

template<class T, size_t N>
GFW__INLINE Vec<T,N> &operator-=(Vec<T,N> &a, const Vec<T,N> &b) noexcept{
	for(size_t i=0;i<N;i++) a[i]-=b[i];
	return a;
}

template<class T, size_t N>
GFW__INLINE Vec<T,N> operator*(const Vec<T,N> &a, T b) noexcept{
	for(size_t i=0;i<N;i++) a[i]*=b;
	return a;
}

template<class T, size_t N>
GFW__INLINE Vec<T,N> &operator*=(Vec<T,N> &a, T b) noexcept{
	for(size_t i=0;i<N;i++) a[i]*=b;
	return a;
}

template<class T, size_t N>
GFW__INLINE Vec<T,N> operator*(T b, const Vec<T,N> &a) noexcept{
	for(size_t i=0;i<N;i++) a[i]*=b;
	return a;
}

template<class T, size_t N>
GFW__INLINE Vec<T,N> operator/(const Vec<T,N> &a, T b) noexcept{
	for(size_t i=0;i<N;i++) a[i]/=b;
	return a;
}

template<class T, size_t N>
GFW__INLINE Vec<T,N> &operator/=(Vec<T,N> &a, T b) noexcept{
	for(size_t i=0;i<N;i++) a[i]/=b;
	return a;
}

template<class T, size_t N>
GFW__INLINE T dot(const Vec<T,N> &a, const Vec<T,N> &b) noexcept{
	T res=a[0]*b[0];
	for(size_t i=1;i<N;i++){
		res+=a[1]*b[1];
	}
	return res;
}

template<class T>
GFW__INLINE T cross(const Vec<T,2> &a, const Vec<T,2> &b) noexcept{
	return a[0]*b[1]-a[1]*b[0];
}

template<class T>
GFW__INLINE Vec<T,3> cross(const Vec<T,3> &a, const Vec<T,3> &b) noexcept{
	return Vec<T,3>(
		a[1]*b[2]-a[2]*b[1],
		a[2]*b[0]-a[0]*b[1],
		a[0]*b[1]-a[1]*b[0]
	);
}

template<class T_>
struct alignas(alignof(T_)) Vec<T_, 1>{
	using value_type=T_;
	static constexpr size_t size=1;
	union{
		value_type data[size];
		struct{
			value_type x;
		};
	};

	GFW__INLINE Vec(value_type x) noexcept:data{x}{}

	GFW__VEC_COMMON
};

template<class T_>
struct alignas(alignof(T_)) Vec<T_, 2>{
	using value_type=T_;
	static constexpr size_t size=2;
	union{
		value_type data[size];
		struct{
			value_type x, y;
		};
	};

	GFW__INLINE Vec(value_type x, value_type y) noexcept:data{x,y}{}

	GFW__VEC_COMMON
};

template<class T_>
struct alignas(alignof(T_)) Vec<T_, 3>{
	using value_type=T_;
	static constexpr size_t size=3;
	union{
		value_type data[size];
		struct{
			value_type x, y, z;
		};
	};

	GFW__INLINE Vec(value_type x, value_type y, value_type z) noexcept:data{x,y,z}{}

	GFW__VEC_COMMON
};

template<class T_>
struct alignas(alignof(T_)) Vec<T_, 4>{
	using value_type=T_;
	static constexpr size_t size=4;
	union{
		value_type data[size];
		struct{
			value_type x, y, z, w;
		};
	};

	GFW__INLINE Vec(value_type x, value_type y, value_type z, value_type w) noexcept:data{x,y,z,w}{}

	GFW__VEC_COMMON
};

template<class T_, size_t N, size_t M>
struct alignas(alignof(T_)) Mat{
	using value_type=T_;
	static constexpr size_t cols=N;
	static constexpr size_t rows=M;
	
	Vec<value_type,rows> data[cols];

	Vec<value_type,rows> &operator[](size_t i) noexcept{
		return data[i];
	}
	const Vec<value_type,rows> &operator[](size_t i) const noexcept{
		return data[i];
	}
};

template<class T, size_t N, size_t M>
GFW__INLINE Mat<T,N,M> operator+(const Mat<T,N,M> &a, const Mat<T,N,M> &b){
	Mat<T,N,M> res;
	for(size_t i=0;i<N;i++){
		res[i]=a[i]+b[i];
	}
	return res;
}

template<class T, size_t N, size_t M, size_t K>
GFW__INLINE Mat<T,K,M> operator*(const Mat<T,N,M> &a, const Mat<T,K,N> &b){
	Mat<T,K,M> res;
	for(size_t j=0;j<K;j++){
		res[j]=a[0]*b[j][0];
		for(size_t i=1;i<N;i++) res[j]+=a[i]*b[j][i];
	}
	return res;
}

template<class T, size_t N, size_t M>
GFW__INLINE Vec<T,M> operator*(const Mat<T,N,M> &a, const Vec<T,N> &b){
	Vec<T,M> res=a[0]*b[0];
	for(size_t i=1;i<N;i++) res+=a[i]*b[i];
	return res;
}

template<class T>
Mat<T,2,2> rot2d(T a){
	T c=std::cos(a), s=std::sin(a);
	return Mat<T,2,2>{
		{c,s},
		{-s,c}
	};
}

#define GFW__VEC_CHECK1(T, N) \
	static_assert(sizeof(::gfw::Vec<T,N>)==N*sizeof(T), ""); \
	static_assert(alignof(::gfw::Vec<T,N>)==alignof(T), ""); \
	static_assert(__builtin_offsetof(::gfw::Vec<T,N>, data)==0, ""); \
	static_assert(__builtin_offsetof(::gfw::Vec<T,N>, x)==0, "")

#define GFW__MAT_CHECK1(T, N, M) \
	static_assert(sizeof(::gfw::Mat<T,N,M>)==N*M*sizeof(T), ""); \
	static_assert(alignof(::gfw::Mat<T,N,M>)==alignof(T), ""); \
	static_assert(__builtin_offsetof(::gfw::Mat<T,N,M>, data)==0, "")

#define GFW__VEC_CHECK(T) \
	GFW__VEC_CHECK1(T, 1); \
	GFW__VEC_CHECK1(T, 2); \
	static_assert(__builtin_offsetof(::gfw::Vec<T,2>, y)==sizeof(T), ""); \
	GFW__VEC_CHECK1(T, 3); \
	static_assert(__builtin_offsetof(::gfw::Vec<T,3>, y)==sizeof(T), ""); \
	static_assert(__builtin_offsetof(::gfw::Vec<T,3>, z)==2*sizeof(T), ""); \
	GFW__VEC_CHECK1(T, 4); \
	static_assert(__builtin_offsetof(::gfw::Vec<T,4>, y)==sizeof(T), ""); \
	static_assert(__builtin_offsetof(::gfw::Vec<T,4>, z)==2*sizeof(T), ""); \
	static_assert(__builtin_offsetof(::gfw::Vec<T,4>, w)==3*sizeof(T), "")

#define GFW__MAT_CHECK(T) \
	GFW__MAT_CHECK1(T, 2, 2); \
	GFW__MAT_CHECK1(T, 2, 3); \
	GFW__MAT_CHECK1(T, 2, 4); \
	GFW__MAT_CHECK1(T, 3, 2); \
	GFW__MAT_CHECK1(T, 3, 3); \
	GFW__MAT_CHECK1(T, 3, 4); \
	GFW__MAT_CHECK1(T, 4, 2); \
	GFW__MAT_CHECK1(T, 4, 3); \
	GFW__MAT_CHECK1(T, 4, 4)

#define GFW__CHECK(T) \
	GFW__VEC_CHECK(T); \
	GFW__MAT_CHECK(T)

}
