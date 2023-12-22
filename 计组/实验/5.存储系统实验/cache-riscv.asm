# file��cache-riscv.asm
# This program accesses an array in ways that provide data about the cache parameters.
# ������ͨ��RARS����cache���������ڴ���ʿ��ӻ����
# �����������cache������cache���ܵ�Ӱ��
# ��������Ĺ��ܿ��Բο�����C����α����
#   int array[];			// ��������Ϊ4�ֽ�
#   for (k=0; k<repcount; k++) {	// repcount����ѭ������
#   // ��������Ԫ�أ����������Щ����Ԫ��ȡ���ڲ���stepsize
#     for (index=0; index<arraysize; index+=stepsize) {
#       if(option==0)
#         array[index]=0;		// option=0���漰һ������д
#       else
#         array[index]=array[index]+1;  
#                      			// option=1���漰����������ʣ���д��һ��
#     }
#   }
          .data
array:   .space    2048     	# array��������ֽڿռ䣬�����޸�
          .text                 	# ����ο�ʼ��־
#########################################################################
# ���¼Ӵ���ֵ�������û��������е��� 
main:	li	a0, 256			# ����ʵ���ֽڴ�С��Ӧ��2���ݴη���С�ڻ����2048��
         	li	a1, 2			# stepsize��Ӧ��2���ݴη���
         	li	a2, 1			# repcount��ѭ��������Ӧ�ô���0��
         	li	a3, 1			# �ô淽ʽ��0 �� option=0��1 �� option=1  
#########################################################################
         	jal	accessWords		# lw/sw
         	jal	accessBytes		# lb/sb	
         	li	a7,10			# exit
         	ecall
# �����мĴ���ʹ��˵��
#  a0 ��arraysize������ʵ���ֽڴ�С
#  a1 ��stepsize��������ʲ���
#  a2 ��number of times to repeat������ѭ�����ʴ���
#  a3 ��0(W)/1(RW)���ô淽ʽ
#  s0 ��moving array ptr�����黬��ָ��
#  s1 ��array limit ptr����������Ͻ�ָ��
accessWords:
			  la	s0, array		# ָ��ָ������
			  add	s1, s0, a0		# �̶���������Ͻ磨ָ�룩
			  slli	t1, a1, 2		# ���Բ���4
wordLoop:
			  beq	a3, zero,  wordZero
			  lw	t0, 0(s0)		# array[index/4]++
			  addi	t0, t0, 1
			  sw	t0, 0(s0)
			  j	wordCheck
wordZero:	
			  sw	zero,	0(s0)		# array[index/4]=0
wordCheck:
			  add	s0, s0, t1		# ָ�����
			  blt	s0,s1,wordLoop  	# ��ѭ��������
			  addi	a2, a2, -1
			  bgtz	a2, accessWords     	# ��ѭ��������
			  jr	ra
accessBytes:
			  la	s0, array	        # ָ��ָ������
			  add	s1, s0, a0		# �̶���������Ͻ磨ָ�룩
byteLoop:
			  beq	a3, zero,  byteZero
			  lbu	t0, 0(s0)		# array[index]++
			  addi	t0, t0, 1
			  sb	t0, 0(s0)
			  j	byteCheck
byteZero:	
			  sb	zero,  0(s0)	        # array[index]=0
byteCheck:
			  add	s0, s0, a1		# ָ�����
			  blt	s0,s1,byteLoop	 	# ��ѭ��������
			  addi	a2, a2, -1
			  bgtz	a2, accessBytes	   	# ��ѭ��������
			  jr	ra
