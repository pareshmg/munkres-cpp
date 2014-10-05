/*
 *   Copyright (c) 2007 John Weaver
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#if !defined(_MATRIX_H_)
#define _MATRIX_H_

#include <initializer_list>

template <class T>
class Matrix {
public:
  Matrix();
  Matrix(const unsigned int rows, const unsigned int columns);
  Matrix(const std::initializer_list<std::initializer_list<T>> init);
  Matrix(const Matrix<T> &other);
  Matrix<T> & operator= (const Matrix<T> &other);
  ~Matrix();
  // all operations modify the matrix in-place.
  void resize(const unsigned int rows, const unsigned int columns, const T default_value = 0);
  void clear();
  T& operator () (const unsigned int x, const unsigned int y);
  const T& operator () (const unsigned int x, const unsigned int y) const;
  const T min() const;
  const T max() const;
  inline unsigned int minsize() {
    return ((m_rows < m_columns) ? m_rows : m_columns);
  }
  inline unsigned int columns() const {
    return m_columns;
  }
  inline unsigned int rows() const {
    return m_rows;
  }
private:
  T **m_matrix;
  unsigned int m_rows;
  unsigned int m_columns;
};

#ifndef USE_EXPORT_KEYWORD
#include "matrix.cpp"
//#define export /*export*/
#endif

#endif /* !defined(_MATRIX_H_) */

