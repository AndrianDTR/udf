<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet
xmlns:xsl='http://www.w3.org/1999/XSL/Transform'
version='1.0'>

<!--
Copyright  2002,2004-2005 The Apache Software Foundation

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

-->
<xsl:param name="title"/>
<xsl:param name="module"/>

<xsl:output method="text" indent="yes" encoding="US-ASCII"
 doctype-public="-//W3C//DTD HTML 4.01//EN"
 doctype-system="http://www.w3.org/TR/html401/strict.dtd"/>

<xsl:template match="*">
<xsl:copy>
<xsl:copy-of select="attribute::*[. != '']"/>
<xsl:apply-templates/>
</xsl:copy>
</xsl:template>

<xsl:template match="changelog">
<xsl:value-of select="$title"/>
<xsl:text>
</xsl:text> 
<xsl:apply-templates select=".//entry">
<xsl:sort select="date" data-type="text" order="descending"/>
<xsl:sort select="time" data-type="text" order="descending"/>
</xsl:apply-templates>
</xsl:template>

<xsl:template match="entry">
<xsl:value-of select="date"/><xsl:text> </xsl:text><xsl:value-of select="time"/><xsl:text> </xsl:text><xsl:value-of select="author"/>
<xsl:apply-templates select="msg"/>
<xsl:text>
</xsl:text> 
<xsl:apply-templates select="file"/>
<xsl:text>
</xsl:text> 
</xsl:template>

<xsl:template match="date">
<xsl:value-of select="."/>
</xsl:template>

<xsl:template match="time">
<xsl:value-of select="."/>
</xsl:template>

<xsl:template match="author">
<xsl:value-of select="."/>
</xsl:template>

<xsl:template match="file">
<xsl:text>	</xsl:text><xsl:value-of select="name" /> (<xsl:value-of select="revision"/>)
</xsl:template>

<xsl:template match="msg">
<!--<xsl:variable name="normalizedMsg" select="normalize-space(.)"/> -->
<xsl:variable name="normalizedMsg" select="."/> 
<xsl:choose>
<xsl:when test="$normalizedMsg = 'no message' ">
</xsl:when>
<xsl:otherwise>
<xsl:text>
</xsl:text> 
<xsl:text>	</xsl:text><xsl:value-of select="$normalizedMsg"/>
</xsl:otherwise>
</xsl:choose> 
</xsl:template>

</xsl:stylesheet>
