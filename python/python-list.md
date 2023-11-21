# python-list

> 以下为自己翻译的简洁版python-help(list)帮助文档

1. 合并

   ```python
   __add__(self, value, /)
   	Return self+value.
   ```

   ```python
   x = [5,9,5,9,5,5,5]
   y = [1,2,3]
   print(list.__add__(x,y))
   ```

   输出： 

   ```python
   [5, 9, 5, 9, 5, 5, 5, 1, 2, 3]
   ```

2. 查找是否元素

   ```python
   __contains__(self, key, /)
   	Return bool(key in self).
   ```

   返回值为bool型

   ```python
   x = [5,9,5,9,5,5,5]
   print(list.__contains__(x,5))
   ```

   输出： 

   ```
   True
   ```

   

3. 删除固定元素

   ```python
   __delitem__(self, key, /)
   	Delete self[key].
   ```

   删除指定元素

4. 

