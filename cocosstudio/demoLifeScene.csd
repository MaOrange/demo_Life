<GameFile>
  <PropertyGroup Name="demoLifeScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Default" ActionTag="953446860" Tag="5" IconVisible="False" LeftMargin="-0.0001" RightMargin="0.0001" TopMargin="-4.1428" BottomMargin="4.1428" ctype="SpriteObjectData">
            <Size X="960.0000" Y="640.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="479.9999" Y="324.1428" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5065" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="HelloWorld.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="lifeRootNode" ActionTag="1095578177" Alpha="231" Tag="11" IconVisible="True" LeftMargin="804.5135" RightMargin="155.4865" TopMargin="165.0731" BottomMargin="474.9269" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="lifeBackground_P" ActionTag="47846343" Tag="13" IconVisible="False" LeftMargin="-151.0000" RightMargin="-151.0000" TopMargin="-16.0000" BottomMargin="-16.0000" ctype="SpriteObjectData">
                <Size X="302.0000" Y="32.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="lifeBackground.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="lifeEffect_LB" ActionTag="112891172" Tag="16" IconVisible="False" LeftMargin="-150.0000" RightMargin="-150.0000" TopMargin="-15.0000" BottomMargin="-15.0000" ProgressInfo="89" ctype="LoadingBarObjectData">
                <Size X="300.0000" Y="30.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="194" B="0" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="lifeOnShow_LB" ActionTag="1497929393" Tag="12" IconVisible="False" LeftMargin="-150.0000" RightMargin="-150.0000" TopMargin="-15.0000" BottomMargin="-15.0000" ProgressInfo="64" ctype="LoadingBarObjectData">
                <Size X="300.0000" Y="30.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="0" G="255" B="25" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="lifeFrame_P" ActionTag="-1588101737" Tag="18" IconVisible="False" LeftMargin="-151.0000" RightMargin="-151.0000" TopMargin="-16.0000" BottomMargin="-16.0000" LeftEage="99" RightEage="99" TopEage="10" BottomEage="10" Scale9OriginX="99" Scale9OriginY="10" Scale9Width="104" Scale9Height="12" ctype="ImageViewObjectData">
                <Size X="302.0000" Y="32.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="lifeFrame.png" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="804.5135" Y="474.9269" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8380" Y="0.7421" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Button_1" ActionTag="872032105" Tag="19" IconVisible="False" LeftMargin="79.8234" RightMargin="680.1766" TopMargin="165.9771" BottomMargin="438.0229" TouchEnable="True" FontSize="14" ButtonText="Damage" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="200.0000" Y="36.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="179.8234" Y="456.0229" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1873" Y="0.7125" />
            <PreSize X="0.2083" Y="0.0562" />
            <TextColor A="255" R="65" G="65" B="70" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Button_2" ActionTag="-1721020251" Tag="9" IconVisible="False" LeftMargin="51.4453" RightMargin="771.5547" TopMargin="301.3523" BottomMargin="287.6477" TouchEnable="True" FontSize="14" ButtonText="Recover" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="137.0000" Y="51.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="119.9453" Y="313.1477" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1249" Y="0.4893" />
            <PreSize X="0.1427" Y="0.0797" />
            <TextColor A="255" R="65" G="65" B="70" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>