# Python-Base

[TOC]

## Type

#### 列表

+ 二维列表： triangle=[[1]]

## Concrete

#### 输出

+ print输出自带换行，如要取消换行，在后尾加上end=‘ ’

  ```python
  print(num,end=' ')
  ```

+ 若要输出类似两个结果间加一个tab键

  ```python
  print(num, end='\t')
  print(1,'\t') #1和tab四个空格间有空隙
  print('1\t') #1和tab四个空格间m有空隙
  ```

+ 

#### 判断

+ 多项判断

  ```python
  if year%4==0 and year%100!=0 or year%400==0:
      isParamyear=True
  ```

#### 循环

+ 只在数组中循环： 

  ```python
  for num in x:
      if num>m1:
          m1=num
  ```

+ 具体递增循环

  ```python
  for i in range(1,num):
      if i>num:
          num=i
  ```

+ 

#### 返回语句

```python
return a
```