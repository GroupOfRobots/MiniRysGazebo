
[NOTE]: "rys.material" file must be copied to:

    /usr/share/gazebo-11/media/materials/scripts/

(It is the path for Gazebo materials)


[Example 1]:

material Rys/Black
{
  technique
  {
    pass
    {
      ambient 0.1 0.1 0.1  <--                                                               (Responsible for overall color)
      diffuse 0.1 0.1 0.1  <--                                                               (Responsible for visibility of the shapes)
      specular 0.4 0.4 0.4 1 5.0 <--                                      (Responsible for highlights)   
    }
  }
}

[Example 2] (Transparent):

material Rys/Lens
{
  technique
  {
    pass
    {
      scene_blend alpha_blend
      depth_write off
      lighting off

      texture_unit
      {
        color_op_ex source1 src_manual src_current 0.75 0.75 0.8 <--         alpha_op_ex source1 src_manual src_current 0.3 <--       }
    }
  }
}
