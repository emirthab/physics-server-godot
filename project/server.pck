GDPC                                                                               <   res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex�      �      ��xV+��]��}]�$   res://Assets/Levels/DemoLevel4.tscn 0      �      V�I�W�f�D&�����    res://Assets/Levels/Level1.tscn �      s      Y�R�f����V��b�   res://Assets/Player.tscn`      �      L�fH���p�)�[7qx7    res://gdnative/NativeLib.gdnlib `      �      �}c�qm=�} �ʋ�s   res://gdnative/Player.gdns         �       �G�L�qs]�4�\$   res://gdnative/ServerManager.gdns   �      �       V�>7<4V��aBJ�p�   res://icon.png  P|      Y      ��{ &+�^a�ݶs��   res://icon.png.import   �+      �      ��fe��6�B��^ U�   res://project.binary��            X(J�u9)Sy�؇;=   res://servergdscript.pck@.      N      �%�B���o;����J[gd_scene load_steps=5 format=2]

[sub_resource type="RectangleShape2D" id=1]
extents = Vector2( 1236, 14.5 )

[sub_resource type="RectangleShape2D" id=2]
extents = Vector2( 18, 611 )

[sub_resource type="RectangleShape2D" id=3]
extents = Vector2( 33, 64 )

[sub_resource type="RectangleShape2D" id=4]
extents = Vector2( 43, 36.5 )

[node name="DemoLevel4" type="Node2D"]

[node name="Collisions" type="StaticBody2D" parent="."]

[node name="CollisionShape2D" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 1237, 193.5 )
shape = SubResource( 1 )

[node name="CollisionShape2D3" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 1237, 1441 )
shape = SubResource( 1 )

[node name="CollisionShape2D2" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 19, 818 )
shape = SubResource( 2 )

[node name="CollisionShape2D5" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 2451, 815 )
shape = SubResource( 2 )

[node name="CollisionShape2D4" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 133, 278 )
shape = SubResource( 3 )

[node name="CollisionShape2D7" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 2369, 352.5 )
shape = SubResource( 4 )

[node name="CollisionShape2D6" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 735, 288 )
shape = SubResource( 3 )

[node name="SpawnPoint" type="Node2D" parent="."]
position = Vector2( 418, 422 )
       [gd_scene load_steps=12 format=2]

[ext_resource path="res://gdnative/ServerManager.gdns" type="Script" id=1]

[sub_resource type="RectangleShape2D" id=1]
extents = Vector2( 499.75, 44.4375 )

[sub_resource type="RectangleShape2D" id=6]
extents = Vector2( 285.938, 60.3594 )

[sub_resource type="RectangleShape2D" id=7]
extents = Vector2( 116.117, 60.3594 )

[sub_resource type="RectangleShape2D" id=12]
extents = Vector2( 13.375, 44.4375 )

[sub_resource type="RectangleShape2D" id=3]
extents = Vector2( 33, 104.219 )

[sub_resource type="RectangleShape2D" id=4]
extents = Vector2( 14.5, 153.109 )

[sub_resource type="RectangleShape2D" id=5]
extents = Vector2( 29.625, 68.4722 )

[sub_resource type="RectangleShape2D" id=8]
extents = Vector2( 72.3125, 27.2361 )

[sub_resource type="RectangleShape2D" id=9]
extents = Vector2( 14.5, 7.38976 )

[sub_resource type="RectangleShape2D" id=10]
extents = Vector2( 11.9628, 31.043 )

[node name="DemoLevel1" type="Node2D"]
position = Vector2( 0, -2 )
script = ExtResource( 1 )

[node name="SpawnPoint" type="Node2D" parent="."]
position = Vector2( 480, 291 )

[node name="Collisions" type="StaticBody2D" parent="."]

[node name="CollisionShape2D" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 495, 34 )
shape = SubResource( 1 )

[node name="CollisionShape2D9" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 488, 533 )
shape = SubResource( 6 )

[node name="CollisionShape2D10" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 864.883, 438 )
shape = SubResource( 7 )

[node name="CollisionShape2D11" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 121, 436 )
shape = SubResource( 7 )

[node name="CollisionShape2D2" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 908, 111 )
shape = SubResource( 12 )

[node name="CollisionShape2D3" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 908, 265.781 )
shape = SubResource( 3 )

[node name="CollisionShape2D4" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 967, 232 )
shape = SubResource( 4 )

[node name="CollisionShape2D5" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 22, 233 )
shape = SubResource( 4 )

[node name="CollisionShape2D6" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 66, 182.528 )
shape = SubResource( 5 )

[node name="CollisionShape2D7" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 165.688, 142.764 )
shape = SubResource( 8 )

[node name="CollisionShape2D8" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 610, 111 )
shape = SubResource( 9 )

[node name="CollisionShape2D13" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 144, 218 )
shape = SubResource( 9 )

[node name="CollisionShape2D12" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 165, 213 )
rotation = 0.366844
shape = SubResource( 10 )
             [gd_scene load_steps=4 format=2]

[ext_resource path="res://gdnative/Player.gdns" type="Script" id=1]

[sub_resource type="CapsuleShape2D" id=1]
radius = 27.0
height = 40.0

[sub_resource type="QuadMesh" id=2]
size = Vector2( 40, 60 )

[node name="Player" type="KinematicBody2D"]
collision_layer = 2
script = ExtResource( 1 )

[node name="CollisionShape2D" type="CollisionShape2D" parent="."]
shape = SubResource( 1 )

[node name="MeshInstance2D" type="MeshInstance2D" parent="."]
mesh = SubResource( 2 )
       [general]

singleton=false
load_once=true
symbol_prefix="godot_"
reloadable=true

[entry]

Windows.64="res://gdnative/windows/libsimple.dll"
Windows.32="res://gdnative/windows/libsimple.dll"
X11.64="res://gdnative/linux/libsimple.so"
X11.32="res://gdnative/linux/libsimple.so"
Server="res://gdnative/linux/libsimple.so"
Server.x86_64="res://gdnative/linux/libsimple.so"
Server.X11.64="res://gdnative/linux/libsimple.so"
Server.X11.32="res://gdnative/linux/libsimple.so"
OSX.64="res://gdnative/osx/libsimple.dylib"

[dependencies]

Windows.64=[  ]
Windows.32=[  ]
X11.64=[  ]
X11.32=[  ]
Server=[  ]
Server.x66_64=[  ]
Server.X11.64=[  ]
Server.X11.32=[  ]
OSX.64=[  ]
    [gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://gdnative/NativeLib.gdnlib" type="GDNativeLibrary" id=1]

[resource]
class_name = "Player"
library = ExtResource( 1 )
        [gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://gdnative/NativeLib.gdnlib" type="GDNativeLibrary" id=1]

[resource]
class_name = "ServerManager"
library = ExtResource( 1 )
 GDST�   �            �  WEBPRIFF�  WEBPVP8L�  /�����^""""J�������WY���՝�����g���0�efffffffjzK����+�eɶ�H������ᏩQi�IY�P��	I�$G�����NeuW�9i���m���j0��.�Q6̵(5��e��P��6�$��I��>&�o����ڴ��xvw�mv���w��A'8�w��
��!5�ϓ_���%��$���ՙ�$K��-/E:ql##A���m���&	6���Ⱛ��$7�I�]Wx���7��骈�e)�bա��-�L�ܞ��Aj�J-R�W�Z�vH���=��Unu(r�Z7�tO鞶Q(�t��R2���J��(���Z6�� %3!5Z6ײ��7�*��H�P�ZuU�p�tB��J�$��-�u�X��c]h�P��O�]&��t�P屔G�J��l�cUF�x�%*�/��]	�J=���1�i��*+�V���ԃ�j�UU>s%{f���a��ժ򙍚?��OH�ˍU�R�.5���)����h;��A7��@v�Qm��*KG[!@v��N��d^_:cU����sU�H�}��r����>T�-�J�A�JH�0n!W�-�*w�7;���D�ƪlE����p��O���W�d�����ښS��է�v|�~8���2{u	����:�㵴�^�]G! ���W����N���<33;s�D-����cj���g�v��hUG��A�� t�����Z��� �������  �˾j����:��h�^&G�Ɗ�{��5�]S�&�����n���Κ)2 ��6���  3E��I7���c2*O��7r�{��4�yW�-�K��W���Jf �j��A�  ų�0(��۲���C k��,�^|  �ؖ/��S�� �#��: \YNN*_S�k �{��j�� (4g���M�0 �p*��N�5�Pd͜Q�� �ݵ���5 P`-Rg�4[ ��%<V7�Cff33{3:��� ��-oS��  �wm5c�  ([<�� �|s�)[ ��5���& �~�J���DTP&��;���/ 0؄Vб�5;7�����i��T����"Q�yW�!-����ٹ -��j�O	 б=I�]`� P}J���� �A�i�m ��2���� ái8t @Fn��aR �Ċ�L, �0)ͷ]rh���7�q-r�� �D��2 ^+}-r�����&�.���.��p��@~�������9*`�G�H�Q	`9*����)���n,�B\���E�915n��ws2�W�  ^���������U  XQ�dX3����lbjx>s+*��&�3]񧡓����I��  ��"��-uv��v, �Z$�/�)9+~Z�k�H# �e7�ȩ�������~D �=|  �WJ��5���_�R  `��W���_?�*^lB@@p��${���Y��/\�w�z��Ӏ@�C�W���R�x����<����qh~��劀`r��~�M�����9����[�=ς�  �E�<�J�ݤ���" ��<s^�_�w�w���Ea��w��Ƚ:���,�g��ө}�ձ�]���ݟ{�tj�G�Y�8���<�w��̵�+�+���q����!I���ajj\�]E`�D~�O���쐨O�i$�%�̳����������*�懯#����,�r�vF@09�"��L�$N�-�붳@Vy6I�������!a9z@@0Ic�gal
'�[k~H��� �p��Yg��!i߬�`�GF@@p�w)s�w�#<��[��N���.������G@�����iK����G�t��bE@��kgiW����f���Y�������o"���#���u�oir�oC����(ƺ3���ɡ�Ejx+���	�Ͻ�]�J��H�{�$��'AzޞcUU:y�v&+��.=�-w��^���"1��?c�����_�%�t1��/c�A�f<*�6����!��W��6��T����K�b���W��s-T����/_zS�y�U��o��K�
�e��)��MV��Ɔ�*��iЁ��9�
��V+��cԿ-�Z�Ҿ9��`v�;@�L
	���s�N���
¤�5 �j���i�|����.T�Pj������W�sd?�n�F�Ƨ�L�e�,  8-T�P�2�À�9|�n��[��Eb�zbxZ�    w�[Bbk�L!1B�@ ����P�OŞC�b �> @'3�0aMb����  �`�P���@�',�b k�*W=`���M�9  ��G+hY_�:���������К��&t�O 7��iY_�`�m�x�Ԅ ^xu�^x5�	!% ̀�ZA�׃�B�@�s�"�. �
a�V�7^�. � �h:G�h:V��AL�x������5�Y(�q!�`+q�?.��	�8.��Pk��x��n����!F_����I��|D��`�ʨt�LT�e
  �WB��j �2���ш���2���t�ʁ  ��2�ʹ�5zm>4  x��!{��R%� ��r'���#@�;Y}�x�J�!{�\R��  ���Y�����^����y�\=JH�7�Y�izI����9��3�i�o��]N���4a���`�m:�����P��"�&�������Y�ݹ�f3��d/v��4�ƛ�F���lw�6kb�M'���;^#h��_j�  �q׊4�y*�n��؝k���YS�����Zl�To?��u��Ⱦ��SE������kii��u�Ƀ�xɃo��(N�� �D�����78@��U���εe}�}7:���5!O��r6 n+g�3z�kB��~8t��Z��s�\��%�7��Bk�YS�}�;WW��אG� �d��l�5 �Js�sm��6k*�㎄�&���� @Hót�#�t�yB ���m�9��  �/�t>��K�g�٬��g߱S�#�e  ��;d�q�<=  s���+�5z�R  P��!��  �>��ы�3W�U���  ��L7�L���Jf�f|hiƇ)�M�Bka8�m6 �/��K �|����6f��T�����6���; �*�k�* ���N�TV���C���6Z�� xq	ũ�K��^Ź��S�����"�}'����s& P*ãT p&���S���+�`(�T�a/�
 ��KŹ9 �mF�1��
�ɨ�����	 ���g���� �-G�[��rE����؞x:�'.��S�qg9�M-_ �W���1
����=�H�����fM����\�εmsV�3���]����&�7��J�͇V�8�njۜ�e���fM���f��4U�/�I��A �b�[�ԯX @�M4"��� ������f%����� ��/�I��^�>�>�Z]����b��Ղ������eAT���	�g׳dң�����c'ƪ *y�nA@@��vrl�K���	�5ۙ�*�j^�]|��~�+N������+cU ��jE@@��k���b�f���=����������B��W+q���Gs����sD ���g�
�����^z�XXf����=�����e����©�|Wm�L��6�wS>�	��Ѿ/�	���ظ�z1ς�*!��Z~�����'����r��J����Z��E� ̫G7؄!��
�oz*)ZחBs�М[7���X�i�Ԑf���DN���Tj�EE����|��dY��X��Yst��s�[ߵ;z�̧<����.*r�U+J/����Z Z���4r���uv����l���}"��OmA�s�;׾�8�4���=�Q�Ǌ]�8q<Թy�SG���z�(7Ϗ5���y�o��Yƣ�`񡣳��G�A���b��j�!Zl���c���G��2U�}�Y��4���8��Q�Giff/�A��_������U�Ҵ��J��+�H�*�B��\i� �R	�[�G�+��H_*}$��˕�t�J��w�h+�d��L�~�eѲo����U�S˾�,]��T#_0.G����TS(�
�tU��"��H�=ˏaϐ"@ZJ�@
��).��`�*�#�R)�R ��(�z*���蓌x�#^�I�"���'!"�	R�/�G�ha�90օF�ȼ)�jm�X(��Ax�*�`fzG�*�<�<ma� �B�搚܀�h�Ra��?,Z-K��ӡ�N9�I�����Ү����[t(�ݢʴ����v�Ԧ�*�H퐾�s{F�)d�:{����        [remap]

importer="texture"
type="StreamTexture"
path="res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex"
metadata={
"vram_texture": false
}

[deps]

source_file="res://icon.png"
dest_files=[ "res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex" ]

[params]

compress/mode=0
compress/lossy_quality=0.7
compress/hdr_mode=0
compress/bptc_ldr=0
compress/normal_map=0
flags/repeat=0
flags/filter=true
flags/mipmaps=false
flags/anisotropic=false
flags/srgb=2
process/fix_alpha_border=true
process/premult_alpha=false
process/HDR_as_SRGB=false
process/invert_color=false
process/normal_map_invert_y=false
stream=false
size_limit=0
detect_3d=true
svg/scale=1.0
              GDPC                                                                               <   res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex`!      �      &�y���ڞu;>��.p   res://Player.tscn   �      
      ��%�s�d(v���_    res://Scripts/Player.gd.remap   0?      )       <y;�9Y;�k��S�   res://Scripts/Player.gdc�      �      �?�Z>�8��
�3���    res://Scripts/Server.gd.remap   `?      )       .OWs��������0�   res://Scripts/Server.gdc�            �#�QdZ_(��ͱ���   res://default_env.tres  �       �       um�`�N��<*ỳ�8   res://icon.png  �?      �      G1?��z�c��vN��   res://icon.png.import   @'      �      ��fe��6�B��^ U�   res://levels/DemoLevel.tscn �)      f      N�+��aB��]I���   res://levels/DemoLevel2.tscn`2      �      sZ� iy�Yw�4&� �   res://levels/DemoLevel3.tscn@4      �
      wt�&В��G�H�\6   res://project.binary�L      �      x8��EK��a��3���            [gd_scene load_steps=4 format=2]

[ext_resource path="res://Scripts/Player.gd" type="Script" id=1]

[sub_resource type="CapsuleShape2D" id=1]
radius = 27.0
height = 40.0

[sub_resource type="QuadMesh" id=2]
size = Vector2( 40, 60 )

[node name="Player" type="KinematicBody2D"]
collision_layer = 2
script = ExtResource( 1 )

[node name="CollisionShape2D" type="CollisionShape2D" parent="."]
shape = SubResource( 1 )

[node name="MeshInstance2D" type="MeshInstance2D" parent="."]
mesh = SubResource( 2 )
      GDSC   2      T        ������������τ�   ����������Ӷ   ����Ҷ��   �������϶���   ��������   ����������Ӷ   ���񶶶�   ��������Ķ��   ����Ķ��   ����   �����������������Ӷ�   ����������������¶��   ���������������¶���   ���������������ض���   �������������ƶ�   �������������������������Ŷ�   �����϶�   ��������Ӷ��   �������¶���   ������¶   ��������Ҷ��   ����¶��   ������������������׶   ��϶   ����Ӷ��   �����Ķ�   ��������������������������Ŷ   ���Ӷ���   ������������������ض   ���������������Ŷ���   ����׶��$   ����������������������������������Ķ   ζ��   ϶��   ���������Ҷ�   �������������Ӷ�   �����Ӷ�   �����Ҷ�   ��������۶��   �����ض�   ���������������¶���   �嶶   ��������������������Ŷ��   ������������������Ŷ   ������Ѷ    ����������������������������¶��   ��������������������������ζ   ����������������������ζ   ��Ŷ   �����������������Ŷ�   �                ?      timeout       pingTimerTimeOut                                    �?            PING :     �        back_idx :        idx :                                                             	      
   '      ,      -      2      7      <      A      B      H      I      O      U      [      f      k      q      r      {            �      �      �       �   !   �   "   �   #   �   $   �   %   �   &   �   '   �   (   �   )   �   *   �   +   �   ,   �   -   �   .     /   	  0   
  1     2     3     4      5   )  6   2  7   9  8   B  9   E  :   F  ;   O  <   R  =   [  >   \  ?   b  @   j  A   z  B   {  C   �  D   �  E   �  F   �  G   �  H   �  I   �  J   �  K   �  L   �  M   �  N   �  O   �  P   �  Q   �  R   �  S     T   3YY;�  Y;�  Y;�  �  T�  YY;�  V�  Y;�  V�  YY;�  �  T�	  PQY;�
  V�  YY;�  �  Y;�  �  Y;�  �  Y;�  �  YY;�  LMYY0�  PQV�  �  T�  �  �  �  T�  �  �  �  T�  P�  RR�  Q�  �  P�  Q�  �  T�  PQ�  Y0�  P�  R�  QV�  /�  V�  �  V�  �  �  �  V�  �  �  �  V�  �  �  �  V�  �  �  �  T�  PL�  P�  QMRL�	  R�  P�  QR�  R�  MQ�  �  PQ�  �  Y0�  P�  QV�  �  P�  Q�  �  �  T�  �  &�  V�  T�   �  �  &�  V�  T�   �  �  &�  V�  T�!  �  �  &�  V�  T�!  �  Y�  &�  �  P�  R�  QV�  �  �  T�"  PQ�  �  �  �#  P�  Q�  YY0�  P�  QV�  &�  V�  �  �  P�
  �  Q�  &�X  P�  Q�  V�  &�X  P�  Q�  V�  �  T�$  P�  Q�  �  T�%  P�&  T�'  Q�  (V�  �  �  T�%  P�&  T�'  Q�  (V�  �  T�%  P�&  T�'  QYY0�(  PQV�  �
  �)  T�*  PQ�  �  T�+  PL�  P�  QMRL�  MQYY0�,  PQV�  �  �)  T�*  PQ�
  YY0�  PQV�  �?  P�  Q�  �?  P�  �>  P�  QQ�  ;�-  P�  �  �  Q�  �  �  ;�.  �  P�  �-  Q�  �?  P�  �>  P�.  QQ�  ;�/  �X  P�  Q�.  �  �?  P�  �>  P�/  QQ�  ;�0  V�  �  &�X  P�  Q�/  V�  �?  P�X  P�  QQ�  �0  �  L�/  M�  �&  T�'  �0  �  �  T�1  PL�  R�  P�  QR�0  T�   R�0  T�!  MQY`         GDSC   :      ^   �     ���Ӷ���   ���ⶶ��   �����Ķ�   ��������������Ķ   ����   ����ض��   �������Ӷ���   ������������Ӷ��   �������Ӷ���   ������Ŷ   �����϶�   �����������Ķ���   ������¶   ��Ķ   �����ض�   ����   ����������Ŷ   ���������Ҷ�   �Ҷ�   ����ٶ��   �����Ķ�   �������Ӷ���   ���Ӷ���   ��������Ҷ��   ������������������Ŷ   �����������������Ŷ�   ƶ��   ζ��   ��������۶��   �����ض�   ϶��   �����Ҷ�   �������������¶�   ���Ӷ���   �����ض�   ���������Ӷ�   ����Ӷ��   ������������Ҷ��   ��������ض��   �������׶���   ��¶   �������Ķ���   ���������¶�   ������������������Ў����   ������������������׶   ������Ѷ   �������������������Ӷ���   ����������Ӷ   ����Ŷ��   �����������Ķ���   ���׶���   ���������¶�   �����Ў�   ��Ŷ   ��������������������������Ŷ   �������Ŷ���   ����׶��   ���ڶ���   4     
   SpawnPoint        client_connected   
   _connected        client_disconnected       _disconnected         client_close_request      _close_request        data_received         _on_data      Unable to start server.           %   Client %d connected with protocol: %s         res://Player.tscn                         2   Client %d disconnecting with code : %d, reason: %s           !   Client %d disconnected, clean: %s                           id        display_name                                            &      '      -   	   1   
   2      8      C      N      Y      d      e      o      u      z            �      �      �      �      �      �      �      �      �      �      �       �   !   �   "     #     $     %      &   -  '   ;  (   B  )   K  *   L  +   M  ,   X  -   f  .   t  /   {  0   �  1   �  2   �  3   �  4   �  5   �  6   �  7   �  8   �  9   �  :   �  ;   �  <   �  =   �  >   �  ?     @     A   
  B     C   '  D   .  E   /  F   >  G   G  H   H  I   I  J   P  K   Y  L   b  M   h  N   x  O   y  P   �  Q   �  R   �  S   �  T   �  U   �  V   �  W   �  X   �  Y   �  Z   �  [   �  \   �  ]   �  ^   3YY:�  Y;�  �  T�  PQY5;�  �  PQT�  T�  P�  QY;�	  LMYY0�
  PQV�  �  PQYY0�  PQV�  �  T�  P�  RR�  Q�  �  T�  P�  RR�  Q�  �  T�  P�  RR�  Q�  �  T�  P�  RR�	  QY�  ;�  �  T�  P�  Q�  &�  �  V�  �?  P�
  Q�  �  P�  QYY0�  P�  R�  QV�  �?  P�  L�  R�  MQ�  ;�  ?P�  QT�  PQ�  �  T�  �>  P�  Q�  �  T�  P�  Q�  �  PL�  MRL�  R�  MQ�  �  PL�  R�  MQ�  �  &�X  P�	  Q�  V�  )�  �	  V�  ;�  �  T�  P�>  P�  QQT�  T�  T�  �  ;�  �  T�  P�>  P�  QQT�  T�  T�  �  �  PL�  MRL�  R�  R�  R�  MQ�  �	  T�  P�  QYY0�   P�  R�!  R�"  QV�  �?  P�  L�  R�!  R�"  MQ�  �  T�  P�>  P�  QQT�#  PQ�  �	  T�$  P�  Q�  �  PL�  R�  MQ�  YY0�%  P�  R�&  �  QV�  �?  P�  L�  R�>  P�&  QMQ�  �  T�  P�>  P�  QQT�#  PQ�  �	  T�$  P�  Q�  �  PL�  R�  MQ�  YY0�'  P�  QV�  ;�(  �  T�)  P�  QT�*  PQT�+  PQ�  �(  �H  P�(  Q<�  �  �  �  /�(  L�  MV�  �  V�  T�  P�>  P�  QQT�,  P�(  L�  MR�(  L�  MQ�  �  V�  T�  P�>  P�  QQT�-  PQ�  �  V�.  P�  R�(  L�  MQYY0�.  P�  R�/  QV�  ;�  �  T�  P�>  P�  QQ�  �  T�/  �/  �  �  ;�0  LM�  )�  �	  V�  ;�1  N�  V�  R�  V�  T�  P�>  P�  QQT�/  O�  �0  T�  P�1  Q�  �  �  PL�  MRL�  R�  R�/  MQ�  �  PL�  R�0  MQYYY0�  P�2  QV�  �2  �G  P�2  Q<�  �  &�X  P�	  Q�  V�  )�  �	  V�  �  T�)  P�  QT�3  P�2  T�4  PQQYY0�  P�5  R�2  QV�  �  �2  �G  P�2  Q<�  �  )�  �5  V�  �  T�)  P�  QT�3  P�2  T�4  PQQYY0�6  P�5  R�2  QV�  �2  �G  P�2  Q<�  �  )�  �	  V�  &�  �5  V�  �  T�)  P�  QT�3  P�2  T�4  PQQYY0�7  P�8  QV�  �  T�9  PQY`[gd_resource type="Environment" load_steps=2 format=2]

[sub_resource type="ProceduralSky" id=1]

[resource]
background_mode = 2
background_sky = SubResource( 1 )
             GDST@   @            �  WEBPRIFF�  WEBPVP8L�  /?����m��������_"�0@��^�"�v��s�}� �W��<f��Yn#I������wO���M`ҋ���N��m:�
��{-�4b7DԧQ��A �B�P��*B��v��
Q�-����^R�D���!(����T�B�*�*���%E["��M�\͆B�@�U$R�l)���{�B���@%P����g*Ųs�TP��a��dD
�6�9�UR�s����1ʲ�X�!�Ha�ߛ�$��N����i�a΁}c Rm��1��Q�c���fdB�5������J˚>>���s1��}����>����Y��?�TEDױ���s���\�T���4D����]ׯ�(aD��Ѓ!�a'\�G(��$+c$�|'�>����/B��c�v��_oH���9(l�fH������8��vV�m�^�|�m۶m�����q���k2�='���:_>��������á����-wӷU�x�˹�fa���������ӭ�M���SƷ7������|��v��v���m�d���ŝ,��L��Y��ݛ�X�\֣� ���{�#3���
�6������t`�
��t�4O��ǎ%����u[B�����O̲H��o߾��$���f���� �H��\��� �kߡ}�~$�f���N\�[�=�'��Nr:a���si����(9Lΰ���=����q-��W��LL%ɩ	��V����R)�=jM����d`�ԙHT�c���'ʦI��DD�R��C׶�&����|t Sw�|WV&�^��bt5WW,v�Ş�qf���+���Jf�t�s�-BG�t�"&�Ɗ����׵�Ջ�KL�2)gD� ���� NEƋ�R;k?.{L�$�y���{'��`��ٟ��i��{z�5��i������c���Z^�
h�+U�mC��b��J��uE�c�����h��}{�����i�'�9r�����ߨ򅿿��hR�Mt�Rb���C�DI��iZ�6i"�DN�3���J�zڷ#oL����Q �W��D@!'��;�� D*�K�J�%"�0�����pZԉO�A��b%�l�#��$A�W�A�*^i�$�%a��rvU5A�ɺ�'a<��&�DQ��r6ƈZC_B)�N�N(�����(z��y�&H�ض^��1Z4*,RQjԫ׶c����yq��4���?�R�����0�6f2Il9j��ZK�4���է�0؍è�ӈ�Uq�3�=[vQ�d$���±eϘA�����R�^��=%:�G�v��)�ǖ/��RcO���z .�ߺ��S&Q����o,X�`�����|��s�<3Z��lns'���vw���Y��>V����G�nuk:��5�U.�v��|����W���Z���4�@U3U�������|�r�?;�
         [remap]

importer="texture"
type="StreamTexture"
path="res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex"
metadata={
"vram_texture": false
}

[deps]

source_file="res://icon.png"
dest_files=[ "res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex" ]

[params]

compress/mode=0
compress/lossy_quality=0.7
compress/hdr_mode=0
compress/bptc_ldr=0
compress/normal_map=0
flags/repeat=0
flags/filter=true
flags/mipmaps=false
flags/anisotropic=false
flags/srgb=2
process/fix_alpha_border=true
process/premult_alpha=false
process/HDR_as_SRGB=false
process/invert_color=false
process/normal_map_invert_y=false
stream=false
size_limit=0
detect_3d=true
svg/scale=1.0
              [gd_scene load_steps=9 format=2]

[sub_resource type="RectangleShape2D" id=1]
extents = Vector2( 487, 61 )

[sub_resource type="RectangleShape2D" id=4]
extents = Vector2( 43.125, 28.5 )

[sub_resource type="RectangleShape2D" id=5]
extents = Vector2( 35.0625, 76.25 )

[sub_resource type="RectangleShape2D" id=6]
extents = Vector2( 20.366, 28.3235 )

[sub_resource type="RectangleShape2D" id=7]
extents = Vector2( 53.2656, 80.125 )

[sub_resource type="RectangleShape2D" id=8]
extents = Vector2( 94.75, 34 )

[sub_resource type="RectangleShape2D" id=9]
extents = Vector2( 35, 121.5 )

[sub_resource type="RectangleShape2D" id=10]
extents = Vector2( 35, 63.75 )

[node name="DemoLevel" type="Node2D"]

[node name="Collisions" type="StaticBody2D" parent="."]

[node name="CollisionShape2D" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 511, 44 )
shape = SubResource( 1 )

[node name="CollisionShape2D5" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 90.875, 132.5 )
shape = SubResource( 4 )

[node name="CollisionShape2D6" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 81.9375, 237.75 )
shape = SubResource( 5 )

[node name="CollisionShape2D8" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 165, 258 )
rotation = 0.704933
shape = SubResource( 6 )

[node name="CollisionShape2D7" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 98.7344, 394.875 )
shape = SubResource( 7 )

[node name="CollisionShape2D2" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 512, 537 )
shape = SubResource( 1 )

[node name="CollisionShape2D9" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 533.25, 268 )
shape = SubResource( 8 )

[node name="CollisionShape2D10" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 936, 226.5 )
shape = SubResource( 9 )

[node name="CollisionShape2D11" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 952, 412 )
shape = SubResource( 10 )

[node name="SpawnPoint" type="Node2D" parent="."]
position = Vector2( 314, 328 )
          [gd_scene load_steps=2 format=2]

[sub_resource type="RectangleShape2D" id=1]
extents = Vector2( 70.588, 48.824 )

[node name="DemoLevel2" type="Node2D"]

[node name="SpawnPoint" type="Node2D" parent="."]
position = Vector2( 314, 328 )

[node name="Collisions" type="StaticBody2D" parent="."]
position = Vector2( 519, 307 )

[node name="CollisionShape2D" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 0, -21.765 )
shape = SubResource( 1 )
      [gd_scene load_steps=11 format=2]

[sub_resource type="RectangleShape2D" id=1]
extents = Vector2( 499.75, 44.4375 )

[sub_resource type="RectangleShape2D" id=6]
extents = Vector2( 285.938, 60.3594 )

[sub_resource type="RectangleShape2D" id=7]
extents = Vector2( 116.117, 60.3594 )

[sub_resource type="RectangleShape2D" id=2]
extents = Vector2( 13.375, 44.4375 )

[sub_resource type="RectangleShape2D" id=3]
extents = Vector2( 33, 104.219 )

[sub_resource type="RectangleShape2D" id=4]
extents = Vector2( 14.5, 153.109 )

[sub_resource type="RectangleShape2D" id=5]
extents = Vector2( 29.625, 68.4722 )

[sub_resource type="RectangleShape2D" id=8]
extents = Vector2( 72.3125, 27.2361 )

[sub_resource type="RectangleShape2D" id=9]
extents = Vector2( 14.5, 7.38976 )

[sub_resource type="RectangleShape2D" id=10]
extents = Vector2( 11.9628, 31.043 )

[node name="DemoLevel3" type="Node2D"]

[node name="SpawnPoint" type="Node2D" parent="."]
position = Vector2( 480, 291 )

[node name="Collisions" type="StaticBody2D" parent="."]

[node name="CollisionShape2D" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 495, 34 )
shape = SubResource( 1 )

[node name="CollisionShape2D9" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 488, 533 )
shape = SubResource( 6 )

[node name="CollisionShape2D10" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 864.883, 438 )
shape = SubResource( 7 )

[node name="CollisionShape2D11" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 121, 436 )
shape = SubResource( 7 )

[node name="CollisionShape2D2" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 908, 111 )
shape = SubResource( 2 )

[node name="CollisionShape2D3" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 908, 265.781 )
shape = SubResource( 3 )

[node name="CollisionShape2D4" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 967, 232 )
shape = SubResource( 4 )

[node name="CollisionShape2D5" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 22, 233 )
shape = SubResource( 4 )

[node name="CollisionShape2D6" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 66, 182.528 )
shape = SubResource( 5 )

[node name="CollisionShape2D7" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 165.688, 142.764 )
shape = SubResource( 8 )

[node name="CollisionShape2D8" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 610, 111 )
shape = SubResource( 9 )

[node name="CollisionShape2D13" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 144, 218 )
shape = SubResource( 9 )

[node name="CollisionShape2D12" type="CollisionShape2D" parent="Collisions"]
position = Vector2( 165, 213 )
rotation = 0.366844
shape = SubResource( 10 )
 [remap]

path="res://Scripts/Player.gdc"
       [remap]

path="res://Scripts/Server.gdc"
       �PNG

   IHDR   @   @   �iq�   sRGB ���  �IDATx��ytTU��?�ի%���@ȞY1JZ �iA�i�[P��e��c;�.`Ow+4�>�(}z�EF�Dm�:�h��IHHB�BR!{%�Zߛ?��	U�T�
���:��]~�������-�	Ì�{q*�h$e-
�)��'�d�b(��.�B�6��J�ĩ=;���Cv�j��E~Z��+��CQ�AA�����;�.�	�^P	���ARkUjQ�b�,#;�8�6��P~,� �0�h%*QzE� �"��T��
�=1p:lX�Pd�Y���(:g����kZx ��A���띊3G�Di� !�6����A҆ @�$JkD�$��/�nYE��< Q���<]V�5O!���>2<��f��8�I��8��f:a�|+�/�l9�DEp�-�t]9)C�o��M~�k��tw�r������w��|r�Ξ�	�S�)^� ��c�eg$�vE17ϟ�(�|���Ѧ*����
����^���uD�̴D����h�����R��O�bv�Y����j^�SN֝
������PP���������Y>����&�P��.3+�$��ݷ�����{n����_5c�99�fbסF&�k�mv���bN�T���F���A�9�
(.�'*"��[��c�{ԛmNު8���3�~V� az
�沵�f�sD��&+[���ke3o>r��������T�]����* ���f�~nX�Ȉ���w+�G���F�,U�� D�Դ0赍�!�B�q�c�(
ܱ��f�yT�:��1�� +����C|��-�T��D�M��\|�K�j��<yJ, ����n��1.FZ�d$I0݀8]��Jn_� ���j~����ցV���������1@M�)`F�BM����^x�>
����`��I�˿��wΛ	����W[�����v��E�����u��~��{R�(����3���������y����C��!��nHe�T�Z�����K�P`ǁF´�nH啝���=>id,�>�GW-糓F������m<P8�{o[D����w�Q��=N}�!+�����-�<{[���������w�u�L�����4�����Uc�s��F�륟��c�g�u�s��N��lu���}ן($D��ת8m�Q�V	l�;��(��ڌ���k�
s\��JDIͦOzp��مh����T���IDI���W�Iǧ�X���g��O��a�\:���>����g���%|����i)	�v��]u.�^�:Gk��i)	>��T@k{'	=�������@a�$zZ�;}�󩀒��T�6�Xq&1aWO�,&L�cřT�4P���g[�
p�2��~;� ��Ҭ�29�xri� ��?��)��_��@s[��^�ܴhnɝ4&'
��NanZ4��^Js[ǘ��2���x?Oܷ�$��3�$r����Q��1@�����~��Y�Qܑ�Hjl(}�v�4vSr�iT�1���f������(���A�ᥕ�$� X,�3'�0s����×ƺk~2~'�[�ё�&F�8{2O�y�n�-`^/FPB�?.�N�AO]]�� �n]β[�SR�kN%;>�k��5������]8������=p����Ցh������`}�
�J�8-��ʺ����� �fl˫[8�?E9q�2&������p��<�r�8x� [^݂��2�X��z�V+7N����V@j�A����hl��/+/'5�3�?;9
�(�Ef'Gyҍ���̣�h4RSS� ����������j�Z��jI��x��dE-y�a�X�/�����:��� +k�� �"˖/���+`��],[��UVV4u��P �˻�AA`��)*ZB\\��9lܸ�]{N��礑]6�Hnnqqq-a��Qxy�7�`=8A�Sm&�Q�����u�0hsPz����yJt�[�>�/ޫ�il�����.��ǳ���9��
_
��<s���wT�S������;F����-{k�����T�Z^���z�!t�۰؝^�^*���؝c
���;��7]h^
��PA��+@��gA*+�K��ˌ�)S�1��(Ե��ǯ�h����õ�M�`��p�cC�T")�z�j�w��V��@��D��N�^M\����m�zY��C�Ҙ�I����N�Ϭ��{�9�)����o���C���h�����ʆ.��׏(�ҫ���@�Tf%yZt���wg�4s�]f�q뗣�ǆi�l�⵲3t��I���O��v;Z�g��l��l��kAJѩU^wj�(��������{���)�9�T���KrE�V!�D���aw���x[�I��tZ�0Y �%E�͹���n�G�P�"5FӨ��M�K�!>R���$�.x����h=gϝ�K&@-F��=}�=�����5���s �CFwa���8��u?_����D#���x:R!5&��_�]���*�O��;�)Ȉ�@�g�����ou�Q�v���J�G�6�P�������7��-���	պ^#�C�S��[]3��1���IY��.Ȉ!6\K�:��?9�Ev��S]�l;��?/� ��5�p�X��f�1�;5�S�ye��Ƅ���,Da�>�� O.�AJL(���pL�C5ij޿hBƾ���ڎ�)s��9$D�p���I��e�,ə�+;?�t��v�p�-��&����	V���x���yuo-G&8->�xt�t������Rv��Y�4ZnT�4P]�HA�4�a�T�ǅ1`u\�,���hZ����S������o翿���{�릨ZRq��Y��fat�[����[z9��4�U�V��Anb$Kg������]������8�M0(WeU�H�\n_��¹�C�F�F�}����8d�N��.��]���u�,%Z�F-���E�'����q�L�\������=H�W'�L{�BP0Z���Y�̞���DE��I�N7���c��S���7�Xm�/`�	�+`����X_��KI��^��F\�aD�����~�+M����ㅤ��	SY��/�.�`���:�9Q�c �38K�j�0Y�D�8����W;ܲ�pTt��6P,� Nǵ��Æ�:(���&�N�/ X��i%�?�_P	�n�F�.^�G�E���鬫>?���"@v�2���A~�aԹ_[P, n��N������_rƢ��    IEND�B`�       ECFG      application/config/name$         saniyelika_headless_server     application/run/main_scene$         res://levels/DemoLevel3.tscn   application/config/icon         res://icon.png     autoload/Server          *res://Scripts/Server.gd)   physics/common/enable_pause_aware_picking         )   rendering/environment/default_environment          res://default_env.tres         �PNG

   IHDR   �   �   �>a�   IDATx��ص�A���$���uw�u�Y��B�yB4%��uu�~�NW}Wv��Fά|kl���꡴H�����Bd�~%:R�G�������E��`�V�a��cS��*�������Ȉ�V>;�f�a����)Z�/EF�Z���0����������1\��эD��ǘb�ձy�*;������V���M�SAS�t�Z��D�&�`�9;L����cisF��ׅg˫��7f�ϒ�h��܉�-�X[��Yĭ�^(9u0h)��eE�`���X�1���D����̩�#��mW�1Ɔ�Ykw��=Z@7�����s�%�}@B���3ߡ۾K�'�{in>� 2�1'6fO8V��]�������^G���ִ�^"��M�C�%�,�[�{�{��B��h�5���|a~�\<�h4ؚ�؋� j��n��A1? nAc{;st���;/9�o��Y�?۶m۶m����X9/���Y�NeP]=�ܽ����={�����2v�v9xᎼx� ����j�|�˥�C�R&eSu�v��B6�$�����R������Q��й>���y¹��DyEuR71�hJ�O全d�	y�)Y������p'R����$Y��8��h,v�T�_} E�R��ģ�y:N���EEe�t��u]��9
ʢLʦ��@lǮ< V� ��#�˓go�&��W������K�-L~[}��>���'���Xe8˥����nb��L�6��G��DbN�l��V:l|����D����J������u�2����O묃���� v� ~p��]����M�ɐ�'b0�5#?d��fXt�u�
�E��,��"6b$Vlx仄Q?��}樃O���_��9ye���y�ȃO<�I�
4���������[������~)}���Q���4�7��(8�k}Ī@�M ��z�^��G{� ��?֯eW�ء��'�*�`�#�?�����0�3�J��X��"Vl(�h�Yw�_eОH����ݺ�M�*�	�r%.E`lb.���p�_u�6<��w���17(H�
4���M�/���ㄠI bU��&�GҾ���4	@�
4���)���"�]V�$ �*�k�	@��5�dؼM��>�$�e�">)/h�Xh@�K�x�Wx�	�߽���'��	�ڏ^T�y�;M��
'�L� V'Є��t�	�8��x|	p'"VjCYy��;{K�ҧz�y�I+$%#GL����AŕW_
��@M�x���m��Z���� ���<]��ȁ̜|���p�䕻���TL��ɔn[C14(�}kX�fh�F��yަÒ��/N\�K<3���� �g�&V�y����	Փ���B[�Z]x.h2�!)M��<���� �vp�x9�;��5?� ��R�	)y�2h�#�kQD�j^�����C��q@& 71�����Q �6�>`���E~�2c0g��\�)��[$цFڏF|��'�T�1^T�[�	��c���=ܕ)�vEH��L9��=���ZK&ъf��:/�T��x0	���Ec f��>������S�U�y@$ �#́Џ�d�%�*��5���Dy�!Q�S�4�׸%���͖ �O\5nh�������Z�5h��m��jӱv�{�D&Xⵂk��h��Q�������k<Wp-�5n=Okb,�Y�͈bb~�5�Z��E��^y*�/��t~4�xK<�kנٞ��o��e劂iX�k�%+�kЬA#la���ۖ����9�DS�+��M��;���[�)�*�<`���Ǥj��/���n`K?��x��k<����SWWk����K�u@�z��+��ܖ~�R��;"�>�"c\�g���1�X�l��N�Hg��mie���Z0�N�BL�F��J�Ď�:��P��x�cs�ȧ�t�+='�ཏ0Q�����}7��'b�hA��	�"T�?(� u�>/	���{&V/�+��u�u��	m?Mx�	X}�Ԇ��y���T0�ԁ-w�6�ŧN'������&@M�#\
K+ĉK/I�������RF�)QQ�ζ�f{&'b2c$fbw�h�	��#�������)�0�V�ر�����;�e��7�{���}��:cDZ��&��Qǹ���;1�^>x�P]���E4�x��	�߮� ��Ç]ňhE�M ��c�b"!!A����2�C��RYY)`ƩXW��0;��\�K�:��M�hIHHh�	�d�M�/_�8���Ⴠ�!����^su.u ��%F4@�M %�0�X�n�O�^�~C����FO � ��K���oh�	�\v���س{�O憄�hWt�' u ��%ƽ{��4�0�:+�����!����� �233�$��6�Q�<��>]:wue��	���6�FO �.@�nbD�hE�M�:n#""�5��?ZIjj��=?PN�' �.@��P_����nn mSp\b���u붴nզFS{��#ϟ?7��5Y�S���Xj����`��)���Qm�+��ʒʬ��d��a�h�"9s������ש.��d	 �����#�svv��@m�A�
�%n��c�O��ʜ�Rq��|.����Є6�蒬�&틎8v���5�8�m�8�k���%&��*g6�pԡ'���ks�i��A�=̼`�[7���F��J��{6��D���&��M K� �6��6
�K�D^Q�p��9G؟���D�y4�NY����v<�<�<�+<���J���2� �I!�X2ӡZĪ�h@�TZ= H�;Xa<� ��`�u����⫍�t�S�I9E~�f�]A�9G��/x�Wx�w�A�h��A��8�D�\u�� 8�}�y���xLl P��8Р@ъf��w>��pr��xs�w��3ʷ�@Y��@�m��[\����{��C��)����>�󉜣�,/1���SOX�� �ƢQ}<t�q����v�"&&y0�sP��e���UFjfN�'��I���#F��	����D�	/��q����b7�Ǒ�E����� �1�D���s��^w_L�82�d,�y�Վ]��
^�D�UP���5Nb&v�/\r�(¢_~�>}Cc�=�\���.�����ߺ���O�v�|���sp��2)۹�8$�z�&O1�bש끟 �]�H�.l�;���3<' �6��Drn�(�0*��].������巓)�|�����w���<��bGZ���L=#
<����?��!�����}��y2��ST 3��2ua8d�%b2۟�8ox�r�C�n�����cj<��C;�[Zm0紓�~Xr	t��Nc�O��aѢH�/��UЮ�g��!Q��y���fK��BQ<��#ml�K<�+�2hV�% dch1	�����v/M��p/�3�cW�9�pcf�'�t�)ǲ�A� p��b�EJ�1M�/�m�^���� p���?�����۟zYy��^�X�������w��q�_�&���f�;�l�I�j�	 G-�*�S2ĉ[/Ҥ����b��:�1)]��i�	 ���$�|�6;o2բ����hs�4]�=��P�>_nG�HM(*��R��~� ���Q�����6O���@9t�&��8^��ոxCțLa��w"	�m�#�sM@�G�2t�F�o�l=���ú�]����Y��d�.ׄd�8�&b!���FOh��U�&��g������KA��=�:��h�gz�X��9�ƛM^sǹ�AY����n�_P�]C����W�6Lv��LV�9-�ff��I�"=;O��X��_�B�M Ol;r���pHN�����	{55���nb�����6��F-����˒'dϙ�����ጦ����,q")-���	�ʢL~���۱ke)�(��'D#�龸���,�:��>
���B���H�f��j��t�S�%���F�+߯����q�c��9[NiQ�[�{1.��?8{�H�`�[c/6ɮ���p4�4����s��?8}�>-+�`.�I����S:��i������_x!8s�a-,�`^ ��}e蜍b��Rxл�x�e��c>t~[d��d�I������I,}[��76fBc;�����k�k�5��+�[[�ӌj����7�����t����c�sM_!L�?���)_�\wH��I��,t�c��8[�d�+���_���dAa��cZv��`�Ex�鄴�?��M�9;��B�tP�h��t\s�����J8O�4?c\�\K�g��KLj�H����� -��=�R��0�C,y�W�^+�h��r�&�)�[Wܲ.�c�����`�V�a��y�(�7+�_�    IEND�B`�       ECFG      application/config/name          Saniyelika-Server-cpp      application/run/main_scene,      #   res://Assets/Levels/DemoLevel4.tscn    application/config/icon         res://icon.png  $   rendering/quality/driver/driver_name         GLES2   7   rendering/quality/intended_usage/framebuffer_allocation          >   rendering/quality/intended_usage/framebuffer_allocation.mobile          %   rendering/vram_compression/import_etc         &   rendering/vram_compression/import_etc2                  