
Player = 
{
	name = "Hero",
	initial_position = { 0.0, -300.0, 0.0 },
	
	SpriteInfo = { 
			SpritePath = "data\\rocket.dds"
	},

	PhysicsInfo = 
	{
		mass = 10.0,
		coefficientOfDrag = 0.001
	},
	velocity = { 0.0, 0.0, 0.0 },
	Center = { 0.0, 50.0, 0.0 },
	BoxExtents = { 50.0, 50.0, 0.0 },
	Roation = 0,
	Controller = "Player2Controller",
	Serializable = 1,
	Trigger = 2
}
