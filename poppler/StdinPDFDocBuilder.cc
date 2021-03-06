//========================================================================
//
// StdinPDFDocBuilder.cc
//
// This file is licensed under the GPLv2 or later
//
// Copyright 2010 Hib Eris <hib@hiberis.nl>
// Copyright 2010, 2017 Albert Astals Cid <aacid@kde.org>
// Copyright 2021 Oliver Sander <oliver.sander@tu-dresden.de>
//
//========================================================================

#include <config.h>

#include "StdinPDFDocBuilder.h"
#include "CachedFile.h"
#include "StdinCachedFile.h"

//------------------------------------------------------------------------
// StdinPDFDocBuilder
//------------------------------------------------------------------------

std::unique_ptr<PDFDoc> StdinPDFDocBuilder::buildPDFDoc(const GooString &uri, GooString *ownerPassword, GooString *userPassword, void *guiDataA)
{
    CachedFile *cachedFile = new CachedFile(new StdinCacheLoader(), nullptr);
    return std::make_unique<PDFDoc>(new CachedFileStream(cachedFile, 0, false, cachedFile->getLength(), Object(objNull)), ownerPassword, userPassword);
}

bool StdinPDFDocBuilder::supports(const GooString &uri)
{
    if (uri.cmpN("fd://0", 6) == 0) {
        return true;
    } else {
        return false;
    }
}
